#include "ExceptionHandler.h"

#include "ExceptionCommand.h"
#include "MoveCommand.h"
#include "UObjectException.h"
#include <iostream>


ExceptionHandler::ExceptionHandler()
{
    std::cout << "\nUObjectPropertyException: " << typeid(UObjectPropertyException).hash_code()
              << "UObjectAbsentPropertyException: " << typeid(UObjectAbsentPropertyException).hash_code()
              << "\n";

    _handlers[typeid(MoveCommand).hash_code()];
    _handlers[typeid(MoveCommand).hash_code()][typeid(UObjectPropertyException).hash_code()] =
              [](const ICommand *cmd, const std::exception &ex) -> ICommand *
              {
                return new WriteExceptionToLogCommand(ex);
              };

    _handlers[typeid(MoveCommand).hash_code()][typeid(UObjectAbsentPropertyException).hash_code()] =
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
            return itEx->second(cmd, exc);
        }
    }

    return nullptr;
}
