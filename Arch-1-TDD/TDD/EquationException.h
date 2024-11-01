#ifndef EQUATIONEXCEPTION_H
#define EQUATIONEXCEPTION_H

#include <exception>

class ZeroCoefficientException : public std::exception
{
public:
    ZeroCoefficientException();

    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

};


#endif // EQUATIONEXCEPTION_H
