#include "MoveCommand.h"

#include "UObjectException.h"

MoveCommand::MoveCommand(std::shared_ptr<IMovingObject> object)
{
    _movingObj = object;
}

void MoveCommand::execute()
{
    if (_movingObj.expired())
    {
        throw CommandExpired();
    }

    auto movObj = _movingObj.lock();

    Vector location = movObj->getLocation();
    Vector velocity = movObj->getVelocity();

    Vector newLocation = location.plus(velocity);

    if ((newLocation.getCoordinate("x") < -20) || newLocation.getCoordinate("y") < -20)
    {
        throw UObjectOutOfSpace();
    }

    movObj->setLocation(location.plus(velocity));
}
