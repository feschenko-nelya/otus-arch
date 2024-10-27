#ifndef EQUATION_H
#define EQUATION_H

#include <vector>

/// Класс расчёта корней квадратного уравнения

class Equation
{
public:
    Equation();

    std::vector<double> solve(const double a, const double b, const double c);

private:
    static const double E;

    double getDiscriminant(const double a, const double b, const double c) const;

};

#endif // EQUATION_H
