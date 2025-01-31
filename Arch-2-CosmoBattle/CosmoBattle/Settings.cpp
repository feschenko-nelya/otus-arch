#include "Settings.h"

#include "LogCommand.h"

Settings::Settings()
{
    setProperty("vector_dimension", 2);
    setProperty("log_file", std::string("./log.log"));
}

Settings &Settings::inst()
{
    static Settings instance;
    return instance;
}

unsigned short Settings::getVectorDimension() const
{
    return std::any_cast<int>(getProperty("vector_dimension"));
}

std::string Settings::getLogFile() const
{
    return std::any_cast<std::string>(getProperty("log_file"));
}

std::queue<std::unique_ptr<AbstractLogCommand>> Settings::getLogCommands(const std::string &text) const
{
    std::queue<std::unique_ptr<AbstractLogCommand>> cmds;

    cmds.push(std::make_unique<ConsoleLogCommand>(text));
    cmds.push(std::make_unique<FileLogCommand>(text));

    return cmds;
}
