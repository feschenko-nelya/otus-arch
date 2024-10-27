#ifndef EQUATION_H
#define EQUATION_H

#include <vector>

/// Класс расчёта корней квадратного уравнения

class Equation
{
public:
    Equation();

    static const double E;

    std::vector<double> solve(const double a, const double b, const double c);

private:
    struct Coefficients
    {
        double a = 0.0;
        double b = 0.0;
        double c = 0.0;
    };

    enum class RootNumber
    {
        First = 1,
        Second = -1
    };

    double getDiscriminant(const Coefficients &coeffs) const;
    double getRoot(const Coefficients &coeffs, const double D, const RootNumber rootNumber) const;

};

#endif // EQUATION_H
