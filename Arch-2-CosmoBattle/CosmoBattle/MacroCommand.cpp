#include "MacroCommand.h"

#include "BurnFuelCommand.h"
#include "CheckFuelCommand.h"
#include "MoveCommand.h"
#include "MovingObject.h"
#include "UObjectException.h"
#include "VehicleObject.h"

MacroMoveCommand::MacroMoveCommand(std::shared_ptr<UObject> object)
{
    _object = object;
}

void MacroMoveCommand::execute()
{
    auto vehicleObject = std::make_shared<VehicleObject>(_object);

    CheckFuelCommand checkFuelCmd(vehicleObject);

    try
    {
        checkFuelCmd.execute();

        auto movObj = std::make_shared<MovingObject>(_object);
        MoveCommand moveCmd(movObj);
        moveCmd.execute();

        BurnFuelCommand burnFuelCmd(vehicleObject);
        burnFuelCmd.execute();
    }
    catch (...)
    {
        throw CommandException();
    }
}
