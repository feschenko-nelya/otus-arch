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

    rotatingObj->setAngle(angle.plus(angularVelocity));
}
