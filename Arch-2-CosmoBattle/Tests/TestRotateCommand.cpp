#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/UObjectException.h"
#include "../CosmoBattle/RotatingObject.h"
#include "../CosmoBattle/RotateCommand.h"

TEST(RotateCommand, Execute)
{
    auto object = std::make_shared<UObject>();
    object->setProperty("angle", Angle{45});
    object->setProperty("angular_velocity", Angle{3});

    auto rotatingObject = std::make_shared<RotatingObject>(object);

    auto rotateCmd = std::make_shared<RotateCommand>(rotatingObject);

    rotateCmd->execute();

    auto angle = rotatingObject->getAngle();

    EXPECT_EQ(angle.value, 48);
}

TEST(RotateCommand, GetAngleException)
{
    auto object = std::make_shared<UObject>();
    object->setProperty("angular_velocity", Angle{3});

    auto rotatingObject = std::make_shared<RotatingObject>(object);

    auto rotateCmd = std::make_shared<RotateCommand>(rotatingObject);

    ASSERT_THROW(rotateCmd->execute(), UObjectAbsentPropertyException);
}

TEST(RotateCommand, GetAngularVelocityException)
{
    auto object = std::make_shared<UObject>();
    object->setProperty("angle", Angle{45});
    object->setProperty("angularVelocity", Angle{3});

    auto rotatingObject = std::make_shared<RotatingObject>(object);

    auto rotateCmd = std::make_shared<RotateCommand>(rotatingObject);

    ASSERT_THROW(rotateCmd->execute(), UObjectAbsentPropertyException);
}

TEST(RotateCommand, SetAngleException)
{
    auto object = std::make_shared<UObject>();
    object->setProperty("angel", Angle{45});
    object->setProperty("angularVelocity", Angle{3});

    auto rotatingObject = std::make_shared<RotatingObject>(object);

    auto rotateCmd = std::make_shared<RotateCommand>(rotatingObject);

    ASSERT_THROW(rotateCmd->execute(), UObjectAbsentPropertyException);
}
