#include <iostream>

#include "Equation.h"

int main(int argc, char *argv[])
{
    Equation x2;

    const double a = 1;
    const double b = 0;
    const double c = 1;

    std::cout << "Coefficients: A = " << a << "; B = " << b << "; C = " << c << "; \n";

    std::cout << "Roots:\n";

    std::vector<double> roots = x2.solve(1, 0, 1);

    if (roots.empty())
    {
        std::cout << "- empty.\n";
    }
    else
    {
        for (int i = 0; i < roots.size(); ++i)
        {
            std::cout << i + 1 << ". " << roots[i] << "\n";
        }
    }

    std::cout << std::endl;

    return -1;
}
