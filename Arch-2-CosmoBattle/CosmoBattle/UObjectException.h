#ifndef UOBJECTEXCEPTION_H
#define UOBJECTEXCEPTION_H

#include <exception>
#include <string>

class UObjectAbsentPropertyException : public std::exception
{
public:
    UObjectAbsentPropertyException() = default;
    UObjectAbsentPropertyException(const std::string &propertyName);
    ~UObjectAbsentPropertyException() = default;

    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

private:
    std::string _propertyName;
};

#endif // UOBJECTEXCEPTION_H
