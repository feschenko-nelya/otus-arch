#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include "UObject.h"

class Vector : private UObject
{
public:
    Vector();
    ~Vector() = default;

    float getCoordinate(const std::string &name) const;
    void setCoordinate(const std::string &name, const float value);

    Vector &plus(const Vector &vector);
    std::string toString() const;
    bool isValid() const;

protected:
    Vector(unsigned short dimension);

private:
    unsigned short _dimension = 0;
};

struct Angle
{
    float value;

    float getRad() const;
    Angle plus(const Angle &angle) const;
};

struct Value
{
    int value = 0;

    bool operator <= (const int &aValue) const;
};

#endif // DATASTRUCTS_H
