#include "EquationException.h"

#include <string>

ZeroCoefficientException::ZeroCoefficientException()
                         :std::exception()
{

}

const char* ZeroCoefficientException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
{
    return "Коэффициент а не должен быть равен 0.";
}
