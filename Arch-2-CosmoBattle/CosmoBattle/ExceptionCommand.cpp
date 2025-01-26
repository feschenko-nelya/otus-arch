#include "ExceptionCommand.h"

#include "LogCommand.h"
#include "Settings.h"

WriteExceptionToLogCommand::WriteExceptionToLogCommand(const std::exception &ex)
{
    _excText = ex.what();
}

void WriteExceptionToLogCommand::execute()
{
    if (Settings::inst().getLogWay() == LogWay::None)
    {
        return;
    }

    if (Settings::inst().getLogWay() == LogWay::All || Settings::inst().getLogWay() == LogWay::Console)
    {
        ConsoleLogCommand cmd(_excText);
        cmd.execute();
    }

    if (Settings::inst().getLogWay() == LogWay::All || Settings::inst().getLogWay() == LogWay::File)
    {
        FileLogCommand cmd(_excText);
        cmd.execute();
    }
}
