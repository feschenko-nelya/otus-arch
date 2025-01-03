#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "ICommand.h"
#include "MovingObject.h"

class MoveCommand : public ICommand
{
public:
    MoveCommand(IMovingObject *object);

    void execute() override;

private:
    IMovingObject *_movingObj = nullptr;

};

#endif // MOVECOMMAND_H
