#include <iostream>

#include "Equation.h"

int main(int argc, char *argv[])
{
    Equation x2;

    const double a = 0;
    const double b = 1;
    const double c = 1;

    std::cout << "Coefficients: A = " << a << "; B = " << b << "; C = " << c << "; \n";

    std::vector<double> roots;

    try
    {
        roots = x2.solve(a, b, c);
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << "\n";
    }

    std::cout << "Roots:\n";
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
