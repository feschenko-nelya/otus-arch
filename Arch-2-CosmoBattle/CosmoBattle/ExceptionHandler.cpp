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
    _handlers[typeid(MoveCommand).hash_code()];
    _handlers[typeid(MoveCommand).hash_code()][typeid(UObjectAbsentPropertyException).hash_code()] = ResultFunction::WriteToLogCmd;
    _handlers[typeid(MoveCommand).hash_code()][typeid(UObjectOutOfSpace).hash_code()] = ResultFunction::RepeatCmdInQueue;

    _handlers[typeid(UObject).hash_code()];
    _handlers[typeid(UObject).hash_code()][typeid(UObjectAbsentPropertyException).hash_code()] = ResultFunction::WriteToLogCmd;

    _handlers[typeid(RotateCommand).hash_code()];
    _handlers[typeid(RotateCommand).hash_code()][typeid(UObjectAbsentPropertyException).hash_code()] = ResultFunction::WriteToLogCmdToCmdQueue;

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
    if (auto itCmd = _handlers.find(typeid(*cmdi).hash_code());
        itCmd != _handlers.end())
    {
        if (auto itEx = itCmd->second.find(typeid(exc).hash_code());
            itEx != itCmd->second.end())
        {
            if (auto itFunc = _funcs.find(itEx->second); itFunc != _funcs.end())
            {
                return itFunc->second(cmd, exc);
            }
        }
    }

    return nullptr;
}

void ExceptionHandler::checkIn(const ICommand *cmd, const std::exception &exc)
{
    const size_t cmdCode = typeid(*cmd).hash_code();
    const size_t excCode = typeid(exc).hash_code();

    auto it = std::find_if(_counter.begin(), _counter.end(),
                           [=](const CommandExceptionCounterData &data)
                           {
                               return ((data.cmd == cmdCode) && (data.exc == excCode));
                           });

    if (it == _counter.end())
    {
        _counter.insert({cmdCode, excCode, 1});
    }
    else
    {
        auto newData = *it;
        ++newData.count;

        _counter.erase(it);
        _counter.insert(newData);
    }
}
