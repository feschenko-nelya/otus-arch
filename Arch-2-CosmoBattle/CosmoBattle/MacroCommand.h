#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "ICommand.h"
#include "UObject.h"

#include <memory>

class MacroMoveCommand : public ICommand
{
public:
    MacroMoveCommand(std::shared_ptr<UObject> object);

    void execute() override;

private:
    std::shared_ptr<UObject> _object;

};

#endif // MACROCOMMAND_H
