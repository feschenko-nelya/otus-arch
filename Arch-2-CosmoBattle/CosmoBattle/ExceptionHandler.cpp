#include "ExceptionHandler.h"

#include "ExceptionCommand.h"
#include "CommandQueue.h"
#include "MoveCommand.h"
#include "RotateCommand.h"
#include "UObjectException.h"
#include <iostream>


ExceptionHandler::ExceptionHandler()
{
    _handlers[typeid(MoveCommand).hash_code()];
    _handlers[typeid(MoveCommand).hash_code()][typeid(UObjectAbsentPropertyException).hash_code()] = ResultCommand::WriteToLogCmd;

    _handlers[typeid(UObject).hash_code()];
    _handlers[typeid(UObject).hash_code()][typeid(UObjectAbsentPropertyException).hash_code()] = ResultCommand::WriteToLogCmd;

    _handlers[typeid(RotateCommand).hash_code()];
    _handlers[typeid(RotateCommand).hash_code()][typeid(UObjectAbsentPropertyException).hash_code()] = ResultCommand::WriteToLogCmdToCmdQueue;

    _funcs[ResultCommand::WriteToLogCmdToCmdQueue] =
              [](const ICommand *cmd, const std::exception &ex) -> ICommand *
              {
                CommandQueue::inst().add(new WriteExceptionToLogCommand(ex));
                return nullptr;
              };

    _funcs[ResultCommand::WriteToLogCmd] =
        [](const ICommand *cmd, const std::exception &ex) -> ICommand *
        {
            return new WriteExceptionToLogCommand(ex);
        };
}

ExceptionHandler &ExceptionHandler::inst()
{
    static ExceptionHandler excHndl;

    return excHndl;
}

ICommand *ExceptionHandler::handle(const ICommand *cmd, const std::exception &exc)
{
    if (auto itCmd = _handlers.find(typeid(*cmd).hash_code());
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
