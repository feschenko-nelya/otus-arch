#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
public:
    static Settings &inst();

    unsigned short getVectorDimension() const;
private:
    Settings();
};

#endif // SETTINGS_H
