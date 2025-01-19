#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/UObjectException.h"
#include "../CosmoBattle/MovingObject.h"
#include "../CosmoBattle/MoveCommand.h"

TEST(MoveCommand, Execute)
{
    UObject object;

    Vector baseLocation;
    baseLocation.setCoordinate("x", 12);
    baseLocation.setCoordinate("y", 5);

    Vector baseVelocity;
    baseVelocity.setCoordinate("x", -7);
    baseVelocity.setCoordinate("y", 3);

    object.setProperty("location", baseLocation);
    object.setProperty("velocity", baseVelocity);
    object.setProperty("angle", Angle{0});

    MovingObject movingObject(&object);

    MoveCommand moveCmd(&movingObject);

    moveCmd.execute();

    auto location = movingObject.getLocation();

    EXPECT_EQ(location.getCoordinate("x"), 5);
    EXPECT_EQ(location.getCoordinate("y"), 5);
}

TEST(MoveCommand, GetLocationException)
{
    UObject object;

    Vector baseLocation;
    baseLocation.setCoordinate("x", 12);
    baseLocation.setCoordinate("y", 5);

    Vector baseVelocity;
    baseVelocity.setCoordinate("x", -7);
    baseVelocity.setCoordinate("y", 3);

    object.setProperty("location1", baseLocation);
    object.setProperty("velocity", baseVelocity);
    object.setProperty("angle", Angle{0});

    MovingObject movingObject(&object);

    MoveCommand moveCmd(&movingObject);

    ASSERT_THROW(moveCmd.execute(), UObjectAbsentPropertyException);
}

TEST(MoveCommand, GetVelocityException)
{
    UObject object;

    Vector baseLocation;
    baseLocation.setCoordinate("x", 12);
    baseLocation.setCoordinate("y", 5);

    Vector baseVelocity;
    baseVelocity.setCoordinate("x", -7);
    baseVelocity.setCoordinate("y", 3);


    object.setProperty("location", baseLocation);
    object.setProperty("velocity1", baseVelocity);
    object.setProperty("angle", Angle{0});

    MovingObject movingObject(&object);

    MoveCommand moveCmd(&movingObject);

    ASSERT_THROW(moveCmd.execute(), UObjectAbsentPropertyException);
}

TEST(MoveCommand, SetLocationException)
{
    UObject object;

    MovingObject movingObject(&object);

    MoveCommand moveCmd(&movingObject);

    ASSERT_THROW(moveCmd.execute(), UObjectAbsentPropertyException);
}
