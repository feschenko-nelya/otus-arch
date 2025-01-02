#include <gtest/gtest.h>

#include "../CosmoBattle/UObject.h"
#include "../CosmoBattle/UObjectException.h"

TEST(UObject, PropertyExceptions)
{
    UObject obj;

    std::any value;

    ASSERT_THROW(obj.getProperty("value"), UObjectAbsentPropertyException);

    obj.setProperty("value", 5);

    ASSERT_NO_THROW(obj.getProperty("value"));
}

TEST(UObject, PropertyExist)
{
    UObject obj;

    obj.setProperty("value", 5);

    const std::any &value = obj.getProperty("value");

    ASSERT_TRUE(value.has_value() == true);
    ASSERT_TRUE(std::any_cast<int>(value) == 5);
}

TEST(UObject, IntProperty)
{
    UObject obj;

    obj.setProperty("value", 5);

    int value = obj.getPropertyInt("value");

    ASSERT_TRUE(value == 5);
}

