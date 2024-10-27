#include "Equation.h"

#include <cstdlib>

const double Equation::E {0.000001};

Equation::Equation()
{

}

const std::vector<double> &Equation::getRoots() const
{
    return _roots;
}

bool Equation::solve(const double a, const double b, const double c)
{
    _roots.clear();

    double D = b * b - 4 * a * c;

    if (std::abs(D) < E)
    {
        return true;
    }

    return true;
}
