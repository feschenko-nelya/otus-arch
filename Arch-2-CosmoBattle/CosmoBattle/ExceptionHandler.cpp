#include "ExceptionHandler.h"

#include "ExceptionCommand.h"
#include "CommandQueue.h"
#include "MoveCommand.h"
#include "RepeatCommand.h"
#include "RotateCommand.h"
#include "UObjectException.h"
#include <iostream>


ExceptionHandler::ExceptionHandler()
{
    _handlers[{typeid(MoveCommand).hash_code(),
               typeid(UObjectAbsentPropertyException).hash_code()}] = ResultFunction::WriteToLogCmd;

    _handlers[{typeid(MoveCommand).hash_code(),
               typeid(UObjectOutOfSpace).hash_code()}] = ResultFunction::RepeatCmdInQueue;

    _handlers[{typeid(UObject).hash_code(),
               typeid(UObjectAbsentPropertyException).hash_code()}] = ResultFunction::WriteToLogCmd;

    _handlers[{typeid(RotateCommand).hash_code(),
               typeid(UObjectAbsentPropertyException).hash_code()}] = ResultFunction::WriteToLogCmdToCmdQueue;
    _handlers[{typeid(RotateCommand).hash_code(),
               typeid(AngleIsInvalidException).hash_code()}] = ResultFunction::OneRepeatThenLogCmd;

    _funcs[ResultFunction::WriteToLogCmdToCmdQueue] =
        [](std::shared_ptr<ICommand> cmd, const std::exception &ex) -> ICommand *
        {
            CommandQueue::inst().add(std::make_shared<WriteExceptionToLogCommand>(ex));
            return nullptr;
        };

    _funcs[ResultFunction::WriteToLogCmd] =
        [](std::shared_ptr<ICommand> cmd, const std::exception &ex) -> ICommand *
        {
            return new WriteExceptionToLogCommand(ex);
        };

    _funcs[ResultFunction::RepeatCmdInQueue] =
        [](std::shared_ptr<ICommand> cmd, const std::exception &ex) -> ICommand *
        {
            CommandQueue::inst().add(std::make_shared<RepeatCommand>(cmd));

            return nullptr;
        };

    _funcs[ResultFunction::OneRepeatThenLogCmd] =
        [=](std::shared_ptr<ICommand> cmd, const std::exception &exc) -> ICommand *
        {
            auto cmdi = cmd.get();
            const size_t cmdCode = typeid(*cmdi).hash_code();
            const size_t excCode = typeid(exc).hash_code();

            auto it = _counter.find({cmdCode, excCode});
            if (it != _counter.end())
            {
                switch (it->second)
                {
                case 1:
                {
                    return new RepeatCommand(cmd);
                }
                case 2:
                {
                    _counter.erase(it);
                    return new WriteExceptionToLogCommand(exc);
                }
                default:
                    break;
                }
            }

            return nullptr;
        };
}

ExceptionHandler &ExceptionHandler::inst()
{
    static ExceptionHandler excHndl;

    return excHndl;
}

ICommand *ExceptionHandler::handle(std::shared_ptr<ICommand> cmd, const std::exception &exc)
{
    checkIn(cmd.get(), exc);

    auto cmdi = cmd.get();

    auto it = _handlers.find({typeid(*cmdi).hash_code(), typeid(exc).hash_code()});

    if (it != _handlers.end())
    {
        if (auto itFunc = _funcs.find(it->second); itFunc != _funcs.end())
        {
            return itFunc->second(cmd, exc);
        }
    }

    return nullptr;
}

void ExceptionHandler::checkIn(const ICommand *cmd, const std::exception &exc)
{
    const size_t cmdCode = typeid(*cmd).hash_code();
    const size_t excCode = typeid(exc).hash_code();

    auto itCmd = _counter.find({cmdCode, excCode});
    if (itCmd == _counter.end())
    {
        _counter.insert({{cmdCode, excCode}, 1});
    }
    else
    {
        ++itCmd->second;
    }
}
