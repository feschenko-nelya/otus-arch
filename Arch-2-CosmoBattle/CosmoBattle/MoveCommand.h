#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "ICommand.h"
#include "MovingObject.h"

class MoveCommand : public ICommand
{
public:
    MoveCommand(std::shared_ptr<IMovingObject> object);

    void execute() override;

private:
    std::weak_ptr<IMovingObject> _movingObj;

};

#endif // MOVECOMMAND_H
