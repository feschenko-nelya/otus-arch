#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "ICommand.h"

class IRotatingObject;

class RotateCommand : public ICommand
{
public:
    RotateCommand(IRotatingObject *object);

    void execute() override;

private:
    IRotatingObject *_rotatingObj = nullptr;
};

#endif // ROTATECOMMAND_H
