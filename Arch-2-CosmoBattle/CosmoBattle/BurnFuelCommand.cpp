#include "BurnFuelCommand.h"

#include "UObjectException.h"
#include <cmath>

BurnFuelCommand::BurnFuelCommand(std::shared_ptr<IVehicleObject> vehicleObj)
{
    _vehicleObj = vehicleObj;
}

void BurnFuelCommand::execute()
{
    if (_vehicleObj.expired())
    {
        throw UObjectExpired();
    }

    auto obj = _vehicleObj.lock();
    Value newValue = obj->getFuelLevel() - obj->getFuelPerStep();
    if (newValue <= 0)
    {
        obj->setFuelLevel(0);
    }
    else
    {
        obj->setFuelLevel(newValue);
    }
}
