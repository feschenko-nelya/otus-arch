#include "LogCommand.h"

#include <iostream>

#include "Settings.h"

AbstractLogCommand::AbstractLogCommand(const std::string &logString)
{
    _logString = logString;
}

void AbstractLogCommand::execute()
{
    if (auto ostream = getOstream())
    {
        ostream->write(_logString.c_str(), _logString.length());
        ostream->flush();
    }
    else
    {
        throw LogCommandException("Log stream is undefined.");
    }
}


ConsoleLogCommand::ConsoleLogCommand(const std::string &logString)
                  :AbstractLogCommand(logString)
{
    _consoleStream = std::make_unique<std::ostream>(std::cout.rdbuf());
}

std::ostream *ConsoleLogCommand::getOstream()
{
    return _consoleStream.get();
}


FileLogCommand::FileLogCommand(const std::string &logString)
               :AbstractLogCommand(logString)
{
    _fileStream = std::make_unique<std::ofstream>();
    _fileStream->open(Settings::inst().getLogFile().c_str(), std::ios::app);
}

std::ostream *FileLogCommand::getOstream()
{
    if (!_fileStream->is_open())
    {
        throw LogCommandException("Log file stream is not opened.");
    }

    return _fileStream.get();
}


LogCommandException::LogCommandException(const std::string &text)
                    :std::exception()
{
    _exceptionText = text;
}

const char* LogCommandException::what() const noexcept
{
    return _exceptionText.c_str();
}


