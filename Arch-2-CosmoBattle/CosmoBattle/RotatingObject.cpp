#include "RotatingObject.h"
#include "UObjectException.h"

RotatingObject::RotatingObject(std::shared_ptr<UObject> object)
{
    _object = object;
}

Angle RotatingObject::getAngle() const
{
    if (_object.expired())
    {
        throw CommandExpired();
    }

    return std::any_cast<Angle>(_object.lock()->getProperty("angle"));
}

Angle RotatingObject::getAngularVelocity() const
{
    if (_object.expired())
    {
        throw CommandExpired();
    }

    return std::any_cast<Angle>(_object.lock()->getProperty("angular_velocity"));
}

void RotatingObject::setAngle(const Angle &angle)
{
    if (_object.expired())
    {
        throw CommandExpired();
    }

    _object.lock()->setProperty("angle", angle);
}
