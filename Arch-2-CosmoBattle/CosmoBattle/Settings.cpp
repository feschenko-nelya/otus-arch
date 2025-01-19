#include "Settings.h"

Settings::Settings()
{
}

Settings &Settings::inst()
{
    static Settings instance;
    return instance;
}

unsigned short Settings::getVectorDimension() const
{
    return 2;
}
