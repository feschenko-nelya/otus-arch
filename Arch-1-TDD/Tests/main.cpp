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
    ASSERT_TRUE(roots.size() == 0);
}

TEST(TestGroup, SubTest_TwoRoots)
{
    Equation eqt;

    // x^2 - 1 = 0
    // Два корня.

    std::vector<double> roots;

    ASSERT_NO_THROW({ roots = eqt.solve(1, 0, -1); });
    ASSERT_TRUE(roots.size() == 2);

    double absRoot1 = std::abs(roots[0]);
    double absRoot2 = std::abs(roots[1]);

    ASSERT_TRUE((absRoot1 >= (1.0 - Equation::E))
                && (absRoot1 <= (1.0 + Equation::E)));

    ASSERT_TRUE((absRoot2 >= (1.0 - Equation::E))
                && (absRoot2 <= (1.0 + Equation::E)));

    // b >= epsilon
    ASSERT_NO_THROW({ roots = eqt.solve(1, Equation::E, -1); });
    ASSERT_TRUE(roots.size() == 2);

    absRoot1 = std::abs(roots.at(0));
    absRoot2 = std::abs(roots.at(1));

    ASSERT_TRUE((absRoot1 >= (1.0 - Equation::E))
                && (absRoot1 <= (1.0 + Equation::E)));

    ASSERT_TRUE((absRoot2 >= (1.0 - Equation::E))
                && (absRoot2 <= (1.0 + Equation::E)));
}

TEST(TestGroup, SubTest_TwoRoots_2)
{
    // Для уравнения x^2+2x+1 = 0 есть один корень кратности 2 (x1 = x2 = -1).

    Equation eqt;

    std::vector<double> roots;

    ASSERT_NO_THROW({ roots = eqt.solve(1, 2, 1); });
    ASSERT_EQ(roots.size(), 1);
    ASSERT_EQ(roots.at(0), -1);
}

TEST(TestGroup, CoeffAIsNotNull)
{
    // Коэффициент a не может быть равен 0. В этом случае solve выбрасывает исключение.

    Equation eqt;

    ASSERT_THROW({ eqt.solve(0, 1, 1); },
                 ZeroCoefficientException);
}

TEST(TestGroup, DiscriminantIsLessThanEpsilon)
{
    // С учетом того, что дискриминант тоже нельзя сравнивать с 0 через знак равенства,
    // подобрать такие коэффициенты квадратного уравнения для случая одного корня кратности два,
    // чтобы дискриминант был отличный от нуля, но меньше заданного эпсилон

    Equation eqt;

    std::vector<double> roots;
    ASSERT_NO_THROW({ roots = eqt.solve(0.000005, 0.00001, 0.000003); });

    ASSERT_EQ(roots.size(), 1);
}

TEST(TestGroup, DoubleTypeCoefficients)
{
    Equation eqt;

    // Корней нет.
    std::vector<double> roots;
    ASSERT_NO_THROW({ roots = eqt.solve(1.0001, 0.0001, 1.001); });
    ASSERT_TRUE(roots.size() == 0);

    // Два корня
    ASSERT_NO_THROW({ roots = eqt.solve(1.00001, 0.00001, -1.00001); });
    ASSERT_TRUE(roots.size() == 2);

    ASSERT_NO_THROW({ roots = eqt.solve(1, 0.005, -1.005); });
    ASSERT_TRUE(roots.size() == 2);

    // Один корень кратности 2
    ASSERT_NO_THROW({ roots = eqt.solve(1.00001, 2.00002, 1.00001); });
    ASSERT_EQ(roots.size(), 1);
    ASSERT_EQ(roots.at(0), -1);

    // исключение для случая а = Epsilon
    ASSERT_THROW({ eqt.solve(Equation::E, 1, 1); },
                 ZeroCoefficientException);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
