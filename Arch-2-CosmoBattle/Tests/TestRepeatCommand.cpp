#include <gtest/gtest.h>
#include <fstream>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/DataStructs.h"
#include "../CosmoBattle/MovingObject.h"
#include "../CosmoBattle/MoveCommand.h"
#include "../CosmoBattle/RepeatCommand.h"

TEST(RepeatCommand, ConsoleLogExecute)
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
    moveCmd->execute();

    auto repeatCmd = std::make_shared<RepeatCommand>(moveCmd);
    ASSERT_NO_THROW(repeatCmd->execute());

    auto location = movingObject->getLocation();

    EXPECT_EQ(location.getCoordinate("x"), -16);
    EXPECT_EQ(location.getCoordinate("y"), 5);
}
