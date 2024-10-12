#ifndef EQUATION_H
#define EQUATION_H

#include <vector>

/// Класс расчёта корней квадратного уравнения

class Equation
{
public:
    Equation();

    void solve(const double a, const double b, const double c);
    const std::vector<double> &getRoots() const;

private:
    static const double E;

    std::vector<double> _roots;

};

#endif // EQUATION_H
