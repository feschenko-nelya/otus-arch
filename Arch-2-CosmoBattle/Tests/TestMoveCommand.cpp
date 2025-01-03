#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/UObjectException.h"
#include "../CosmoBattle/MovingObject.h"
#include "../CosmoBattle/MoveCommand.h"

TEST(MoveCommand, Execute)
{
    UObject object;
    object.setProperty("location", Vector{12, 5});
    object.setProperty("velocity", Vector{-7, 3});
    object.setProperty("angle", Angle{0});

    MovingObject movingObject(&object);

    MoveCommand moveCmd(&movingObject);

    moveCmd.execute();

    auto location = movingObject.getLocation();

    EXPECT_EQ(location.x, 5);
    EXPECT_EQ(location.y, 5);
}

TEST(MoveCommand, GetLocationException)
{
    UObject object;
    object.setProperty("location1", Vector{12, 5});
    object.setProperty("velocity", Vector{-7, 3});
    object.setProperty("angle", Angle{0});

    MovingObject movingObject(&object);

    MoveCommand moveCmd(&movingObject);

    ASSERT_THROW(moveCmd.execute(), UObjectAbsentPropertyException);
}

TEST(MoveCommand, GetVelocityException)
{
    UObject object;
    object.setProperty("location", Vector{12, 5});
    object.setProperty("velocity1", Vector{-7, 3});
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
