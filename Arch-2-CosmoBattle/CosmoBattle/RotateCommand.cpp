#include "RotateCommand.h"

#include "RotatingObject.h"
#include "UObjectException.h"

RotateCommand::RotateCommand(std::shared_ptr<IRotatingObject> object)
{
    _rotatingObj = object;
}

void RotateCommand::execute()
{
    if (_rotatingObj.expired())
    {
        throw CommandExpired();
    }

    auto rotatingObj = _rotatingObj.lock();
    const Angle angle = rotatingObj->getAngle();
    const Angle angularVelocity = rotatingObj->getAngularVelocity();

    const Angle newAngle = angle.plus(angularVelocity);

    if (newAngle.value > 360 || newAngle.value < 0)
    {
        throw AngleIsInvalidException();
    }

    rotatingObj->setAngle(newAngle);
}
