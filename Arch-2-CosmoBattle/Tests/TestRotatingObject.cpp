#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/RotatingObject.h"

TEST(RotatingObject, GetAngle)
{
    auto object = std::make_shared<UObject>();
    object->setProperty("angle", Angle{45});

    RotatingObject rotatingObject(object);

    Angle angle = rotatingObject.getAngle();

    EXPECT_EQ(angle.value, 45);
    EXPECT_NEAR(angle.getRad(), 0.7853981634, 0.000001);
}

TEST(RotatingObject, GetAngularVelocity)
{
    auto object = std::make_shared<UObject>();
    object->setProperty("angle", Angle{45});
    object->setProperty("angular_velocity", Angle{1});

    RotatingObject rotatingObject(object);

    const Angle angularVelocity = rotatingObject.getAngularVelocity();

    EXPECT_EQ(angularVelocity.value, 1);
}

TEST(RotatingObject, SetAngle)
{
    auto object = std::make_shared<UObject>();
    object->setProperty("angle", Angle{45});
    object->setProperty("angular_velocity", Angle{1});

    auto rotatingObject = std::make_shared<RotatingObject>(object);

    Angle angle = rotatingObject->getAngle();
    const Angle angularVelocity = rotatingObject->getAngularVelocity();

    rotatingObject->setAngle(angle.plus(angularVelocity));

    EXPECT_EQ(rotatingObject->getAngle().value, 46);
}
