#include "RotateCommand.h"

#include "RotatingObject.h"

RotateCommand::RotateCommand(IRotatingObject *object)
{
    _rotatingObj = object;
}

void RotateCommand::execute()
{
    const Angle angle = _rotatingObj->getAngle();
    const Angle angularVelocity = _rotatingObj->getAngularVelocity();

    _rotatingObj->setAngle(angle.plus(angularVelocity));
}
