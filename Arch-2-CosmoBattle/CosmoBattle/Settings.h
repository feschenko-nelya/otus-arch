#ifndef SETTINGS_H
#define SETTINGS_H

#include "UObject.h"

#include <string>

enum class LogWay
{
    None,
    All,
    Console,
    File
};


class Settings : protected UObject
{
public:
    static Settings &inst();

    unsigned short getVectorDimension() const;
    std::string getLogFile() const;
    LogWay getLogWay() const;

private:
    Settings();
};

#endif // SETTINGS_H
