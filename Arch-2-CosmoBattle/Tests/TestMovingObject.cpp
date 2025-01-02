#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"

TEST(MovingObject, GetLocation)
{
    UObject object;
    object.setProperty("location", Vector{12, 5});

    MovingObject movingObject(&object);

    Vector location = movingObject.getLocation();

    ASSERT_TRUE(location.x == 12);
    ASSERT_TRUE(location.y == 5);
}

TEST(MovingObject, SetLocation)
{
    UObject object;
    object.setProperty("location", Vector{12, 5});

    MovingObject movingObject(&object);

    movingObject.setLocation(Vector{15, 8});

    Vector location = movingObject.getLocation();

    ASSERT_TRUE(location.x == 15);
    ASSERT_TRUE(location.y == 8);
}

TEST(MovingObject, GetVelocity)
{
    UObject object;
    object.setProperty("location", Vector{12, 5});
    object.setProperty("velocity", Vector{-7, 3});
    object.setProperty("angle", 0);

    MovingObject movingObject(&object);

    movingObject.getVelocity();

    Vector velocity = movingObject.getVelocity();

    ASSERT_TRUE(velocity.x == 5);
    ASSERT_TRUE(velocity.y == 8);
}
