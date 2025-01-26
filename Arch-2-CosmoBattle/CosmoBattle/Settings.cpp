#include "Settings.h"

Settings::Settings()
{
    setProperty("vector_dimension", 2);
    setProperty("log_file", std::string("./log.log"));
    setProperty("log_way", LogWay::All);
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

LogWay Settings::getLogWay() const
{
    return std::any_cast<LogWay>(getProperty("log_way"));
}
