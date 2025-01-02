#include "UObjectException.h"

UObjectAbsentPropertyException::UObjectAbsentPropertyException(const std::string &propertyName)
{
    _propertyName = propertyName;
}

const char* UObjectAbsentPropertyException::what() const noexcept
{
    return std::string("The property '").append(_propertyName).append("' is absent.").c_str();
}
