#include "RotatingObject.h"

RotatingObject::RotatingObject(UObject *object)
{
    _object = object;
}

Angle RotatingObject::getAngle() const
{
    return std::any_cast<Angle>(_object->getProperty("angle"));
}

Angle RotatingObject::getAngularVelocity() const
{
    return std::any_cast<Angle>(_object->getProperty("angularVelocity"));
}

void RotatingObject::setAngle(const Angle &angle)
{
    _object->setProperty("angle", angle);
}
