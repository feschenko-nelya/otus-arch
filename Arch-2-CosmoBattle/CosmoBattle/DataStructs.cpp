#include "DataStructs.h"

#include "UObjectException.h"
#include "Settings.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

Vector::Vector()
       :Vector(Settings::inst().getVectorDimension())
{
}

Vector::Vector(unsigned short dimension)
{
    _dimension = dimension;
}

float Vector::getCoordinate(const std::string &name) const
{
    return std::any_cast<float>(getProperty(name));
}

void Vector::setCoordinate(const std::string &name, const float value)
{
    if (!hasProperty(name) && (getPropertiesCount() == _dimension))
    {
        throw VectorOutOfDimensionException(name, getPropertiesNames());
    }

    setProperty(name, value);
}

Vector &Vector::plus(const Vector &vector)
{
    if (_dimension != vector._dimension)
    {
        throw VectorOperationException("plus", toString());
    }

    const auto propertiesNames = getPropertiesNames();

    std::unordered_map<std::string, std::any> propertiesCopy;
    for (auto it = propertiesNames.cbegin(); it != propertiesNames.cend(); ++it)
    {
        propertiesCopy[*it] = getCoordinate(*it) + vector.getCoordinate(*it);
    }

    for (auto it = propertiesCopy.cbegin(); it != propertiesCopy.cend(); ++it)
    {
        setProperty(it->first, it->second);
    }

    return *this;
}

std::string Vector::toString() const
{
    std::string result;

    const auto propertiesNames = getPropertiesNames();

    for (auto it = propertiesNames.cbegin(); it != propertiesNames.cend(); ++it)
    {
        result.append(*it).append(" = ").append(std::to_string(getCoordinate(*it))).append("\n");
    }

    return result;
}

bool Vector::isValid() const
{
    return (getCoordinate("x") >= Settings::inst().getSpaceLowXLimit())
           && (getCoordinate("y") >= Settings::inst().getSpaceLowYLimit())
           && (getCoordinate("x") <= Settings::inst().getSpaceHighXLimit())
           && (getCoordinate("y") <= Settings::inst().getSpaceHighYLimit());
}


// ----------------- Angle -----------------------

float Angle::getRad() const
{
    return value * M_PI / 180;
}

Angle Angle::plus(const Angle &angle) const
{
    return Angle{value + angle.value};
}
