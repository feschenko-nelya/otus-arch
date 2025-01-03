#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/MovingObject.h"

TEST(MovingCommand, Execute)
{
    UObject object;
    object.setProperty("location", Vector{12, 5});
    object.setProperty("velocity", Vector{-7, 3});

    MovingObject movingObject(&object);

    MovingCommand moveCmd(&movingObject);

    moveCmd.execute();

    auto location = movingObject.getLocation();

    EXPECT_EQ(location.x, 5);
    EXPECT_EQ(location.y, 8);
}
