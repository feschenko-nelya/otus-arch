#include "DataStructs.h"

#include <cmath>

float Angle::getRad() const
{
    return value * M_PI / 180;
}

Angle Angle::plus(const Angle &angle)
{
    return Angle{value + angle.value};
}
