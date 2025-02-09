#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/VehicleObject.h"
#include "../CosmoBattle/CheckFuelCommand.h"
#include "../CosmoBattle/UObjectException.h"

TEST(CheckFuelCommand, Execute)
{
    auto object = std::make_shared<UObject>();

    auto vehicle = std::make_shared<VehicleObject>(object);
    vehicle->setFuelLevel({100});

    auto cmd = std::make_shared<CheckFuelCommand>(vehicle);
    ASSERT_NO_THROW(cmd->execute());

    EXPECT_EQ(vehicle->getFuelLevel().value, 100);

    vehicle->setFuelLevel({0});

    ASSERT_THROW(cmd->execute(), ObjectHasNoFuelException);

    EXPECT_EQ(vehicle->getFuelLevel().value, 0);
}

TEST(BurnFuelCommand, Execute)
{
    auto object = std::make_shared<UObject>();

    auto vehicle = std::make_shared<VehicleObject>(object);
    vehicle->setFuelLevel({100});

    auto cmd = std::make_shared<BurnFuelCommand>(vehicle);
    ASSERT_NO_THROW(cmd->execute());

    EXPECT_EQ(vehicle->getFuelLevel().value, 99);

    vehicle->setFuelLevel({0});

    ASSERT_THROW(cmd->execute(), ObjectHasNoFuelException);

    EXPECT_EQ(vehicle->getFuelLevel().value, 0);
}
