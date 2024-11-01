#include "Equation.h"

#include <cmath>
#include <cstdlib>
#include <iostream>

#include "EquationException.h"

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

    const Coefficients coeffs{a, b, c};

    const double D = getDiscriminant(coeffs);

    if (D <= -E)
    {
        return {};
    }

    if (D > E)
    {
        if (std::abs(a) <= E)
        {
            throw ZeroCoefficientException();
        }

        std::vector<double> roots;
        roots.reserve(2);

        roots.push_back(getRoot(coeffs, D, RootNumber::First));
        roots.push_back(getRoot(coeffs, D, RootNumber::Second));

        return roots;
    }

    if (D <= E)
    {
        std::vector<double> roots;
        roots.reserve(1);

        roots.push_back(getRoot(coeffs, D, RootNumber::First));

        return roots;
    }

    return {};
}

double Equation::getDiscriminant(const Coefficients &coeffs) const
{
    return coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
}

double Equation::getRoot(const Coefficients &coeffs, const double D, const RootNumber rootNumber) const
{
    return (-coeffs.b + static_cast<double>(rootNumber) * std::sqrt(D)) / (2.0 * coeffs.a);
}
