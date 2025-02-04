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

    const char* what() const noexcept override;
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

    const char* what() const noexcept override;

};

class UObjectOutOfSpace : public std::exception
{
public:
    UObjectOutOfSpace() = default;
    ~UObjectOutOfSpace() = default;

    const char* what() const noexcept override;
};

class VectorOutOfDimensionException : public UObjectPropertyException
{
public:
    VectorOutOfDimensionException() = default;
    VectorOutOfDimensionException(const std::string &coordinateName, const std::set<std::string> &coordinatesNames);
    ~VectorOutOfDimensionException() = default;

    const char* what() const noexcept override;

private:
    std::set<std::string> _coordinatesNames;
};

class VectorOperationException : std::exception
{
public:
    VectorOperationException() = default;
    VectorOperationException(const std::string &operationName, const std::string &vectorDataStr);
    ~VectorOperationException() = default;

    const char* what() const noexcept override;

private:
    std::string _operationName;
    std::string _vectorDataStr;

};

class AngleIsMoreThan360Exception : public std::exception
{
public:
    AngleIsMoreThan360Exception() = default;
    ~AngleIsMoreThan360Exception() = default;

    const char* what() const noexcept override;
};

class AngleIsLessThan0Exception : public std::exception
{
public:
    AngleIsLessThan0Exception() = default;
    ~AngleIsLessThan0Exception() = default;

    const char* what() const noexcept override;
};


class CommandExpired : public std::exception
{
public:
    CommandExpired() = default;
    ~CommandExpired() = default;

    const char* what() const noexcept override;
};

#endif // UOBJECTEXCEPTION_H
