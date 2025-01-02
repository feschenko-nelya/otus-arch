#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/UObjectException.h"

TEST(TestGroup, TestPropertyExceptions)
{
    UObject obj;

    std::any value;

    ASSERT_THROW(obj.getProperty("value"), UObjectAbsentPropertyException);

    obj.setProperty("value", 5);

    ASSERT_NO_THROW(obj.getProperty("value"));
}

TEST(TestGroup, TestPropertyExist)
{
    UObject obj;

    obj.setProperty("value", 5);

    const std::any &value = obj.getProperty("value");

    ASSERT_TRUE(value.has_value() == true);
    ASSERT_TRUE(std::any_cast<int>(value) == 5);
}

TEST(TestGroup, TestIntProperty)
{
    UObject obj;

    obj.setProperty("value", 5);

    int value = obj.getPropertyInt("value");

    ASSERT_TRUE(value == 5);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
