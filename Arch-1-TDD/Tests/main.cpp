#include <cmath>
#include <gtest/gtest.h>

#include "../TDD/Equation.h"
#include "../TDD/EquationException.h"

TEST(TestGroup, SubTest_x2p1)
{
    Equation eqt;

    // x^2 + 1 = 0
    // Корней нет.

    std::vector<double> roots;
    ASSERT_NO_THROW({ roots = eqt.solve(1, 0, 1); });
    ASSERT_TRUE(eqt.solve(1, 0, 1).size() == 0);
}

TEST(TestGroup, SubTest_TwoRoots)
{
    Equation eqt;

    // x^2 - 1 = 0
    // Два корня.

    std::vector<double> roots;

    ASSERT_NO_THROW({ roots = eqt.solve(1, 0, -1); });
    ASSERT_TRUE(roots.size() == 2);

    const double root1 = roots[0];
    const double root2 = roots[1];

    int rootInt = static_cast<int>(root1);
    ASSERT_TRUE((rootInt == 1) && (std::abs(root1 - rootInt) < Equation::E));

    rootInt = static_cast<int>(root2);
    ASSERT_TRUE((rootInt == -1) && (std::abs(root2) - std::abs(rootInt) < Equation::E));
}

TEST(TestGroup, SubTest_TwoRoots_2)
{
    // Для уравнения x^2+2x+1 = 0 есть один корень кратности 2 (x1 = x2 = -1).

    Equation eqt;

    std::vector<double> roots;

    ASSERT_NO_THROW({ roots = eqt.solve(1, 4, 4); });
    ASSERT_EQ(roots.size(), 1);

    double dblRoot = std::abs(roots.at(0) / 2.0);
    int intRoot = static_cast<int>(dblRoot);
    bool hasRootDiv2 = ((dblRoot - intRoot) < Equation::E);

    ASSERT_TRUE(hasRootDiv2);
}

TEST(TestGroup, CoeffAIsNotNull)
{
    // Коэффициент a не может быть равен 0. В этом случае solve выбрасывает исключение.

    Equation eqt;

    ASSERT_THROW({ eqt.solve(0, 1, 1); },
                 ZeroCoefficientException);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
