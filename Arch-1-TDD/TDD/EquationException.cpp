#include "EquationException.h"

#include <string>

ZeroCoefficientException::ZeroCoefficientException()
                         :std::exception()
{

}

const char* ZeroCoefficientException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
{
    return "Cofficient 'a' must be nonzero.";
}
