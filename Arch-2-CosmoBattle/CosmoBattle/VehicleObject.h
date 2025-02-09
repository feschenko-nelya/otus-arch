#ifndef VEHICLEOBJECT_H
#define VEHICLEOBJECT_H

#include "DataStructs.h"
#include <memory>

class IVehicleObject
{
public:
    virtual ~IVehicleObject() = default;

    virtual void setFuelLevel(const Value &value) = 0;
    virtual Value getFuelLevel() const = 0;
    virtual Value getFuelPerStep() const = 0;
};

class VehicleObject : public IVehicleObject
{
public:
    VehicleObject(std::shared_ptr<UObject> object);

    void setFuelLevel(const Value &value) override;
    Value getFuelLevel() const override;
    Value getFuelPerStep() const override;

private:
    std::weak_ptr<UObject> _object;
};

#endif // VEHICLEOBJECT_H
