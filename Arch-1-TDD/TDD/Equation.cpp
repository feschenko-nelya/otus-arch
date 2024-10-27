#include "Equation.h"

#include <cstdlib>

const double Equation::E {0.000001};

Equation::Equation()
{

}

std::vector<double> Equation::solve(const double a, const double b, const double c)
{
    if ((std::abs(a) < E) && (std::abs(b) < E) && (std::abs(c) < E))
    {
        return {};
    }

    const double D = getDiscriminant(a, b, c);

    if (std::abs(D) < E)
    {
        return {};
    }

    return {};
}

double Equation::getDiscriminant(const double a, const double b, const double c) const
{
    return b * b - 4 * a * c;
}
