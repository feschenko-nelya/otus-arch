#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/MovingObject.h"

TEST(MovingObject, GetLocation)
{
    UObject object;

    Vector baseLocation;
    baseLocation.setCoordinate("x", 12);
    baseLocation.setCoordinate("y", 5);

    object.setProperty("location", baseLocation);

    MovingObject movingObject(&object);

    Vector location = movingObject.getLocation();

    EXPECT_EQ(location.getCoordinate("x"), 12);
    EXPECT_EQ(location.getCoordinate("y"), 5);
}

TEST(MovingObject, SetLocation)
{
    UObject object;

    Vector baseLocation;
    baseLocation.setCoordinate("x", 12);
    baseLocation.setCoordinate("y", 5);

    object.setProperty("location", baseLocation);

    MovingObject movingObject(&object);

    Vector newLocation;
    newLocation.setCoordinate("x", 5);
    newLocation.setCoordinate("y", 8);

    movingObject.setLocation(newLocation);

    Vector location = movingObject.getLocation();

    EXPECT_EQ(location.getCoordinate("x"), 5);
    EXPECT_EQ(location.getCoordinate("y"), 8);
}

TEST(MovingObject, GetVelocity)
{
    UObject object;

    Vector newLocation;
    newLocation.setCoordinate("x", -7);
    newLocation.setCoordinate("y", 3);

    object.setProperty("velocity", newLocation);
    object.setProperty("angle", Angle{0});

    MovingObject movingObject(&object);

    Vector velocity = movingObject.getVelocity();

    EXPECT_EQ(velocity.getCoordinate("x"), -7);
    EXPECT_EQ(velocity.getCoordinate("y"), 0);
}
