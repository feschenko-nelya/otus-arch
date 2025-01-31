#include "MovingObject.h"

#include "UObjectException.h"

#include <cmath>

MovingObject::MovingObject(std::shared_ptr<IUObject> object)
{
    _object = object;
}

Vector MovingObject::getLocation()
{
    if (_object.expired())
    {
        throw UObjectExpired();
    }

    return std::any_cast<Vector>(_object.lock()->getProperty("location"));
}

void MovingObject::setLocation(const Vector &location)
{
    if (_object.expired())
    {
        throw UObjectExpired();
    }

    _object.lock()->setProperty("location", location);
}

Vector MovingObject::getVelocity()
{
    if (_object.expired())
    {
        throw UObjectExpired();
    }

    auto curObject = _object.lock();
    Vector velocity = std::any_cast<Vector>(curObject->getProperty("velocity"));
    Angle angle = std::any_cast<Angle>(curObject->getProperty("angle"));

    const float rad = angle.getRad();

    Vector result = velocity;
    result.setCoordinate("x", velocity.getCoordinate("x") * cos(rad));
    result.setCoordinate("y", velocity.getCoordinate("y") * sin(rad));

    return result;
}
