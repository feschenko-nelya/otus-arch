#include <gtest/gtest.h>

#include "../CosmoBattle/Settings.h"
#include "../CosmoBattle/DataStructs.h"
#include "../CosmoBattle/UObjectException.h"

class TestVector : public Vector
{
public:
    TestVector() : Vector(3) {}
};

TEST(Vector, Settings)
{
    EXPECT_TRUE(Settings::inst().getVectorDimension() > 1);
}


TEST(Vector, PropertyException)
{
    Vector vector;

    std::any value;

    ASSERT_THROW(vector.getCoordinate("x"), UObjectAbsentPropertyException);
}

TEST(Vector, PlusException)
{
    Vector vector2d;
    vector2d.setCoordinate("x", 0);
    vector2d.setCoordinate("y", 0);

    TestVector vector3d;

    ASSERT_NO_THROW(vector3d.setCoordinate("x", 1));
    ASSERT_NO_THROW(vector3d.setCoordinate("y", 2));
    ASSERT_NO_THROW(vector3d.setCoordinate("z", 3));

    ASSERT_THROW(vector3d.setCoordinate("a", 4), VectorOutOfDimensionException);
    ASSERT_THROW(vector2d.plus(vector3d), VectorOperationException);

    Vector vector2d_2;
    vector2d_2.setCoordinate("x", 4);
    vector2d_2.setCoordinate("y", -6);

    ASSERT_NO_THROW(vector2d.plus(vector2d_2));

    EXPECT_EQ(vector2d.getCoordinate("x"), 4);
    EXPECT_EQ(vector2d.getCoordinate("y"), -6);
}
