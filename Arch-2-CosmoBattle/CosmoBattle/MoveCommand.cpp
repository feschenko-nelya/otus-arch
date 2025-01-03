#include "MoveCommand.h"

MoveCommand::MoveCommand(IMovingObject *object)
{
    _movingObj = object;
}

void MoveCommand::execute()
{
    Vector location = _movingObj->getLocation();
    Vector velocity = _movingObj->getVelocity();

    _movingObj->setLocation({location.x + velocity.x,
                             location.y + velocity.y});

}
