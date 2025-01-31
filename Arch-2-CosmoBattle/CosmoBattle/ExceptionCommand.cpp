#include "ExceptionCommand.h"

#include "LogCommand.h"
#include "Settings.h"

WriteExceptionToLogCommand::WriteExceptionToLogCommand(const std::exception &ex)
{
    _excText = ex.what();
}

void WriteExceptionToLogCommand::execute()
{
    auto cmds = Settings::inst().getLogCommands(_excText);

    while (!cmds.empty())
    {
        cmds.front()->execute();
        cmds.pop();
    }
}
