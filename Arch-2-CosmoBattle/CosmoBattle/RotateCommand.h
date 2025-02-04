#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "ICommand.h"
#include <memory>

class IRotatingObject;

class RotateCommand : public ICommand
{
public:
    RotateCommand(std::shared_ptr<IRotatingObject> object);

    void execute() override;

private:
    std::weak_ptr<IRotatingObject> _rotatingObj;
};

#endif // ROTATECOMMAND_H
