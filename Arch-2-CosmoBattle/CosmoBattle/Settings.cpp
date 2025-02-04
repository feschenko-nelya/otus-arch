#include "Settings.h"

#include "LogCommand.h"

Settings::Settings()
{
    setProperty("vector_dimension", 2);

    setProperty("space_low_x_limit", -2000);
    setProperty("space_low_y_limit", -2000);

    setProperty("space_high_x_limit", 2000);
    setProperty("space_high_y_limit", 2000);

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

int Settings::getSpaceLowXLimit() const
{
    return std::any_cast<int>(getProperty("space_low_x_limit"));
}

int Settings::getSpaceLowYLimit() const
{
    return std::any_cast<int>(getProperty("space_low_y_limit"));
}

int Settings::getSpaceHighXLimit() const
{
    return std::any_cast<int>(getProperty("space_high_x_limit"));
}

int Settings::getSpaceHighYLimit() const
{
    return std::any_cast<int>(getProperty("space_high_y_limit"));
}

std::string Settings::getLogFile() const
{
    return std::any_cast<std::string>(getProperty("log_file"));
}

std::queue<std::unique_ptr<AbstractLogCommand>> Settings::getLogCommands(const std::string &text) const
{
    std::queue<std::unique_ptr<AbstractLogCommand>> cmds;

#ifndef COSMO_TEST
    cmds.push(std::make_unique<ConsoleLogCommand>(text));
#endif
    cmds.push(std::make_unique<FileLogCommand>(text));

    return cmds;
}
