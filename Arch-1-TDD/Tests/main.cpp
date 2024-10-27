#include <cmath>
#include <gtest/gtest.h>

#include "../TDD/Equation.h"

TEST(TestGroup, SubTest_x2p1)
{
    Equation eqt;

    // x^2 + 1 = 0
    // Корней нет.

    ASSERT_TRUE(eqt.solve(1, 0, 1).size() == 0);
}

TEST(TestGroup, SubTest_TwoRoots)
{
    Equation eqt;

    // x^2 - 1 = 0
    // Два корня.

    std::vector<double> roots = eqt.solve(1, 0, -1);
    ASSERT_TRUE(roots.size() == 2);

    const double root1 = roots[0];
    const double root2 = roots[1];

    int rootInt = static_cast<int>(root1);
    ASSERT_TRUE((rootInt == 1) && (std::abs(root1 - rootInt) < Equation::E));

    rootInt = static_cast<int>(root2);
    ASSERT_TRUE((rootInt == -1) && (std::abs(root2) - std::abs(rootInt) < Equation::E));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
