#include <cmath>
#include <gtest/gtest.h>
#include <fstream>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/Settings.h"
#include "../CosmoBattle/DataStructs.h"
#include "../CosmoBattle/MovingObject.h"
#include "../CosmoBattle/MoveCommand.h"
#include "../CosmoBattle/RepeatCommand.h"

TEST(RepeatCommand, ExecuteOnce)
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

    auto movingObject = std::make_shared<MovingObject>(object);
    auto moveCmd = std::make_shared<MoveCommand>(movingObject);
    auto repeatCmd = std::make_shared<RepeatCommand>(moveCmd);
    ASSERT_NO_THROW(repeatCmd->execute());

    auto location = movingObject->getLocation();

    EXPECT_EQ(location.getCoordinate("x"), 5);
    EXPECT_EQ(location.getCoordinate("y"), 5);
}

TEST(RepeatCommand, ExecuteTwice)
{
    auto object = std::make_shared<UObject>();

    Vector baseLocation;
    baseLocation.setCoordinate("x", 0);
    baseLocation.setCoordinate("y", 1);

    Vector baseVelocity;
    baseVelocity.setCoordinate("x", 3);
    baseVelocity.setCoordinate("y", 3);

    object->setProperty("location", baseLocation);
    object->setProperty("velocity", baseVelocity);
    object->setProperty("angle", Angle{45});

    auto movingObject = std::make_shared<MovingObject>(object);
    auto moveCmd = std::make_shared<MoveCommand>(movingObject);
    auto repeatCmd = std::make_shared<RepeatTwiceCommand>(moveCmd);

    ASSERT_NO_THROW(repeatCmd->execute());

    auto location = movingObject->getLocation();

    EXPECT_EQ(std::round(location.getCoordinate("x")), 2);
    EXPECT_EQ(std::round(location.getCoordinate("y")), 3);
}

TEST(RepeatCommand, ExecuteTwiceThenLog)
{
    auto object = std::make_shared<UObject>();

    Vector baseLocation;
    baseLocation.setCoordinate("x", 0);
    baseLocation.setCoordinate("y", 1);

    Vector baseVelocity;
    baseVelocity.setCoordinate("x", Settings::inst().getSpaceHighXLimit() + 1);
    baseVelocity.setCoordinate("y", Settings::inst().getSpaceHighYLimit() + 1);

    object->setProperty("location", baseLocation);
    object->setProperty("velocity", baseVelocity);
    object->setProperty("angle", Angle{0});

    auto movingObject = std::make_shared<MovingObject>(object);
    auto moveCmd = std::make_shared<MoveCommand>(movingObject);
    auto repeatCmd = std::make_shared<RepeatTwiceCommand>(moveCmd);
    ASSERT_NO_THROW(repeatCmd->execute());

    auto location = movingObject->getLocation();

    EXPECT_EQ(std::round(location.getCoordinate("x")), 0);
    EXPECT_EQ(std::round(location.getCoordinate("y")), 1);
}
