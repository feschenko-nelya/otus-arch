#include <gtest/gtest.h>

#include "../CosmoBattle/MovingObject.h"
#include "../CosmoBattle/VehicleObject.h"
#include "../CosmoBattle/DataStructs.h"

TEST(MacroCommand, Execute)
{
    auto object = std::make_shared<UObject>();

    Vector baseLocation;
    baseLocation.setCoordinate("x", 12);
    baseLocation.setCoordinate("y", 5);

    Vector baseVelocity;
    baseVelocity.setCoordinate("x", -7);
    baseVelocity.setCoordinate("y", 3);

    object->setProperty("location", baseLocation);
    object->setProperty("velocity", baseVelocity);
    object->setProperty("angle", Angle{0});

    auto vehObject = std::make_shared<VehicleObject>();
    vehObject->setFuelLevel(0);

    auto macroCom = std::make_shared<MacroMoveCommand>(object);
    ASSERT_THROW(macroCom->execute(), CommandException);

    vehObject->setFuelLevel(100);
    ASSERT_NO_THROW(macroCom->execute());

    auto movingObject = std::make_shared<MovingObject>(object);
    auto location = movingObject->getLocation();

    EXPECT_EQ(location.getCoordinate("x"), 5);
    EXPECT_EQ(location.getCoordinate("y"), 5);

    EXPECT_EQ(vehObject->getFuelLevel().value, 99);
}
