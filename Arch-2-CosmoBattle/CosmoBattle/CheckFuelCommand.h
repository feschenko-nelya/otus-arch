#ifndef CHECKFUELCOMMAND_H
#define CHECKFUELCOMMAND_H

#include "ICommand.h"
#include "VehicleObject.h"

#include <memory>

class CheckFuelCommand : public ICommand
{
public:
    CheckFuelCommand(std::shared_ptr<IVehicleObject> vehicleObject);

    void execute() override;

private:
    std::weak_ptr<IVehicleObject> _vehicleObject;
};

#endif // CHECKFUELCOMMAND_H
