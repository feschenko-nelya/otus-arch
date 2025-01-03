#include "MovingObject.h"
#include <cmath>

float Angle::getRad() const
{
    return value * M_PI / 180;
}

MovingObject::MovingObject(IUObject *object)
{
    _object = object;
}

Vector MovingObject::getLocation()
{
    return std::any_cast<Vector>(_object->getProperty("location"));
}

void MovingObject::setLocation(const Vector &location)
{
    _object->setProperty("location", location);
}

Vector MovingObject::getVelocity()
{
    return std::any_cast<Vector>(_object->getProperty("velocity"));
}
