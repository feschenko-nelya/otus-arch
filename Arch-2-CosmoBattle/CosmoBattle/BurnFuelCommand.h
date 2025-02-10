#ifndef BURNFUELCOMMAND_H
#define BURNFUELCOMMAND_H

#include "ICommand.h"
#include "VehicleObject.h"

#include <memory>

class BurnFuelCommand : public ICommand
{
public:
    BurnFuelCommand(std::shared_ptr<IVehicleObject> vehicleObj);

    void execute() override;

private:
    std::weak_ptr<IVehicleObject> _vehicleObj;
};

#endif // BURNFUELCOMMAND_H
