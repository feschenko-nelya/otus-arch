#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/UObjectException.h"
#include "../CosmoBattle/RotatingObject.h"
#include "../CosmoBattle/MoveCommand.h"

TEST(RotateCommand, Execute)
{
    UObject object;
    object.setProperty("angle", Angle{45});
    object.setProperty("angular_velocity", Angle{3});

    RotatingObject rotatingObject(&object);

    RotateCommand rotateCmd(&rotatingObject);

    rotateCmd.execute();

    auto angle = rotatingObject.getAngle();

    EXPECT_EQ(angle.value, 48);
}

TEST(RotateCommand, GetAngleException)
{
    UObject object;
    object.setProperty("angular_velocity", Angle{3});

    RotatingObject rotatingObject(&object);

    RotateCommand rotateCmd(&rotatingObject);

    ASSERT_THROW(rotateCmd.execute(), UObjectAbsentPropertyException);
}

TEST(RotateCommand, GetAngularVelocityException)
{
    UObject object;
    object.setProperty("angle", Angle{45});
    object.setProperty("angularVelocity", Angle{3});

    RotatingObject rotatingObject(&object);

    RotateCommand rotateCmd(&rotatingObject);

    ASSERT_THROW(rotateCmd.execute(), UObjectAbsentPropertyException);
}

TEST(RotateCommand, SetAngleException)
{
    UObject object;
    object.setProperty("angel", Angle{45});
    object.setProperty("angularVelocity", Angle{3});

    RotatingObject rotatingObject(&object);

    RotateCommand rotateCmd(&rotatingObject);

    ASSERT_THROW(rotateCmd.execute(), UObjectAbsentPropertyException);
}
