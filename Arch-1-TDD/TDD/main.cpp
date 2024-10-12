#include <iostream>

#include "Equation.h"

int main(int argc, char *argv[])
{
    Equation x2;

    for (double root : x2.getRoots())
    {
        std::cout << root << " ";
    }

    std::cout << std::endl;

    return -1;
}
