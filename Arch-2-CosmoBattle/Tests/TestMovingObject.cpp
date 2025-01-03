#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/MovingObject.h"

TEST(MovingObject, GetLocation)
{
    UObject object;
    object.setProperty("location", Vector{12, 5});

    MovingObject movingObject(&object);

    Vector location = movingObject.getLocation();

    EXPECT_EQ(location.x, 12);
    EXPECT_EQ(location.y, 5);
}

TEST(MovingObject, SetLocation)
{
    UObject object;
    object.setProperty("location", Vector{12, 5});

    MovingObject movingObject(&object);

    movingObject.setLocation(Vector{5, 8});

    Vector location = movingObject.getLocation();

    EXPECT_EQ(location.x, 5);
    EXPECT_EQ(location.y, 8);
}

TEST(MovingObject, GetVelocity)
{
    UObject object;
    object.setProperty("velocity", Vector{-7, 3});
    object.setProperty("angle", Angle{0});

    MovingObject movingObject(&object);

    Vector velocity = movingObject.getVelocity();

    EXPECT_EQ(velocity.x, -7);
    EXPECT_EQ(velocity.y, 0);
}
