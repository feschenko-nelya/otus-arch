#ifndef SETTINGS_H
#define SETTINGS_H

#include "UObject.h"

#include <memory>
#include <queue>
#include <string>


class Settings : protected UObject
{
public:
    static Settings &inst();

    unsigned short getVectorDimension() const;
    std::string getLogFile() const;
    std::queue<std::unique_ptr<class AbstractLogCommand>> getLogCommands(const std::string &text) const;

private:
    Settings();
};

#endif // SETTINGS_H
