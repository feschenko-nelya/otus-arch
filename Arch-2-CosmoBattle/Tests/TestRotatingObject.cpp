#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/RotatingObject.h"

TEST(RotatingObject, GetAngle)
{
    UObject object;
    object.setProperty("angle", Angle{45});

    RotatingObject rotatingObject(&object);

    Angle angle = rotatingObject.getAngle();

    EXPECT_EQ(angle.value, 45);
    EXPECT_NEAR(angle.getRad(), 0.7853981634, 0.00000000001);
}

TEST(RotatingObject, GetAngularVelocity)
{
    UObject object;
    object.setProperty("angle", Angle{45});
    object.setProperty("angularVelocity", 1);

    RotatingObject rotatingObject(&object);

    const int angularVelocity = rotatingObject.getAngularVelocity();

    EXPECT_EQ(angularVelocity, 1);
}

TEST(RotatingObject, SetAngle)
{
    UObject object;
    object.setProperty("angle", Angle{45});
    object.setProperty("angularVelocity", 1);

    RotatingObject rotatingObject(&object);

    Angle angle = rotatingObject.getAngle();
    const int angularVelocity = rotatingObject.getAngularVelocity();

    rotatingObject.setAngle(angle.plus(angularVelocity));

    EXPECT_EQ(rotatingObject.getAngle().value, 46);
}
