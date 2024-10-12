#include "Equation.h"

const double Equation::E {0.000001};

Equation::Equation()
{

}

const std::vector<double> &Equation::getRoots() const
{
    return _roots;
}
