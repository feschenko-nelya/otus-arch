#include <gtest/gtest.h>

#include "../TDD/Equation.h"

TEST(TestGroup, SubTest_1)
{
    Equation eqt;

    ASSERT_TRUE(eqt.getRoots().size() == 0);
}

TEST(TestGroup, SubTest_x2p1)
{
    Equation eqt;

    // x^2 + 1 = 0
    // Корней нет.

    ASSERT_TRUE(eqt.solve(1, 0, 1));
    ASSERT_TRUE(eqt.getRoots().size() == 0);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
