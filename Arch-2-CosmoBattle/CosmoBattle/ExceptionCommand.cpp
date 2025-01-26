#include "ExceptionCommand.h"

#include "LogCommand.h"
#include "Settings.h"

WriteExceptionToLogCommand::WriteExceptionToLogCommand(std::exception *ex)
{
    _ex = ex;
}

void WriteExceptionToLogCommand::execute()
{
    if (Settings::inst().getLogWay() == LogWay::None)
    {
        return;
    }

    if (Settings::inst().getLogWay() == LogWay::All || Settings::inst().getLogWay() == LogWay::Console)
    {
        ConsoleLogCommand cmd(_ex->what());
        cmd.execute();
    }

    if (Settings::inst().getLogWay() == LogWay::All || Settings::inst().getLogWay() == LogWay::File)
    {
        FileLogCommand cmd(_ex->what());
        cmd.execute();
    }
}
