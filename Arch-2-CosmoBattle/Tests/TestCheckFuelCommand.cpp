#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/VehicleObject.h"
#include "../CosmoBattle/CheckFuelCommand.h"

TEST(CheckFuelCommand, Execute)
{
    auto object = std::make_shared<UObject>();

    auto vehicle = std::make_shared<VehicleObject>(object);
    vehicle->setFuel(100);

    auto cmd = std::make_shared<CheckFuelCommand>(vehicle);
    cmd->execute();

    EXPECT_EQ(vehicle->hasFuel(), true);

    vehicle->setFuel(0);

    cmd->execute();

    EXPECT_EQ(vehicle->hasFuel(), false);
}
