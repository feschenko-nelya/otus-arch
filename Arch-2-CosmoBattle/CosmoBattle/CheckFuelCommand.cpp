#include "CheckFuelCommand.h"

#include "UObjectException.h"

CheckFuelCommand::CheckFuelCommand(std::shared_ptr<IVehicleObject> vehicleObject)
{
    _vehicleObject = vehicleObject;
}

void CheckFuelCommand::execute()
{
    if (_vehicleObject.expired())
    {
        throw UObjectExpired();
    }

    if (_vehicleObject.lock()->getFuelLevel() <= 0)
    {
        throw ObjectHasNoFuelException();
    }
}
