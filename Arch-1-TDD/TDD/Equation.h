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
    double getDiscriminant(const double a, const double b, const double c) const;

};

#endif // EQUATION_H
