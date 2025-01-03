#include "MovingObject.h"
#include <cmath>

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
    Vector velocity = std::any_cast<Vector>(_object->getProperty("velocity"));
    Angle angle = std::any_cast<Angle>(_object->getProperty("angle"));

    return {static_cast<int>(velocity.x * cos(angle.getRad())),
            static_cast<int>(velocity.y * sin(angle.getRad()))};
}
