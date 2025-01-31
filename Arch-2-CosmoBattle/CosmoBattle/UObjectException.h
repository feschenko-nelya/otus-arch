#ifndef UOBJECTEXCEPTION_H
#define UOBJECTEXCEPTION_H

#include <exception>
#include <string>
#include <set>

class UObjectExpired : public std::exception
{
public:
    UObjectExpired() = default;
    ~UObjectExpired() = default;

    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;
};

class UObjectPropertyException : public std::exception
{
public:
    UObjectPropertyException() = default;
    UObjectPropertyException(const std::string &propertyName);
    ~UObjectPropertyException() = default;

protected:
    std::string _propertyName;

};

class UObjectAbsentPropertyException : public UObjectPropertyException
{
public:
    UObjectAbsentPropertyException() = default;
    UObjectAbsentPropertyException(const std::string &propertyName);
    ~UObjectAbsentPropertyException() = default;

    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

};

class VectorOutOfDimensionException : public UObjectPropertyException
{
public:
    VectorOutOfDimensionException() = default;
    VectorOutOfDimensionException(const std::string &coordinateName, const std::set<std::string> &coordinatesNames);
    ~VectorOutOfDimensionException() = default;

    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

private:
    std::set<std::string> _coordinatesNames;
};

class VectorOperationException : std::exception
{
public:
    VectorOperationException() = default;
    VectorOperationException(const std::string &operationName, const std::string &vectorDataStr);
    ~VectorOperationException() = default;

    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

private:
    std::string _operationName;
    std::string _vectorDataStr;

};

#endif // UOBJECTEXCEPTION_H
