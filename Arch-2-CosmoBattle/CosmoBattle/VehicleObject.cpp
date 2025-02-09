#include "VehicleObject.h"
#include "UObjectException.h"

VehicleObject::VehicleObject(std::shared_ptr<UObject> object)
{
    _object = object;
}

void VehicleObject::setFuelLevel(const Value &value)
{
    if (_object.expired())
    {
        throw UObjectExpired();
    }

    _object.lock()->setProperty("fuel_level", value);
}

Value VehicleObject::getFuelLevel() const
{
    if (_object.expired())
    {
        throw UObjectExpired();
    }

    return std::any_cast<Value>(_object.lock()->getProperty("fuel_level"));
}
