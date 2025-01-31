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
        throw UObjectExpired();
    }

    auto movObj = _movingObj.lock();

    Vector location = movObj->getLocation();
    Vector velocity = movObj->getVelocity();

    movObj->setLocation(location.plus(velocity));
}
