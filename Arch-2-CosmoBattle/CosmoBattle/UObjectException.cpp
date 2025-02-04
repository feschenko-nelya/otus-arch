#include "UObjectException.h"

const char* UObjectExpired::what() const noexcept
{
    return "Object is expired.";
}

UObjectPropertyException::UObjectPropertyException(const std::string &propertyName)
{
    _propertyName = propertyName;
}

// ------------ UObjectPropertyException ---------------- //

UObjectAbsentPropertyException::UObjectAbsentPropertyException(const std::string &propertyName)
                               :UObjectPropertyException(propertyName)
{
}

const char* UObjectAbsentPropertyException::what() const noexcept
{
    return std::string("The property '").append(_propertyName).append("' is absent.").c_str();
}

// --------------------------- UObjectOutOfSpace ----------------------------//

const char* UObjectOutOfSpace::what() const noexcept
{
    return "Object is out of space.";
}

// -------------------------- AngleIsMoreThan360Exception ----------------------- //

const char* AngleIsMoreThan360Exception::what() const noexcept
{
    return "Angle is invalid: angle > 360 || angle < 0";
}

// -------------------------- AngleIsLessThan0Exception ----------------------- //

const char* AngleIsLessThan0Exception::what() const noexcept
{
    return "Angle is invalid: angle < 0";
}


// --------------- VectorOutOfDimensionException ---------------- //

VectorOutOfDimensionException::VectorOutOfDimensionException(const std::string &propertyName,
                                                             const std::set<std::string> &coordinatesNames)
                              :UObjectPropertyException(propertyName)
{
    _coordinatesNames = coordinatesNames;
}

const char* VectorOutOfDimensionException::what() const noexcept
{
    std::string coordinatesNamesStr;
    for (auto it = _coordinatesNames.cbegin(); it != _coordinatesNames.cend(); ++it)
    {
        coordinatesNamesStr.append("- ");
        coordinatesNamesStr.append(*it);
        coordinatesNamesStr.append("\n");
    }

    return std::string("The coordinate '")
           .append(_propertyName)
           .append("' is not owned by this vector.\n"
                   "Vector coordinates are:\n")
           .append(coordinatesNamesStr)
        .c_str();
}

// --------------- VectorDimensionIsDifferException ---------------- //

VectorOperationException::VectorOperationException(const std::string &operationName, const std::string &vectorDataStr)
{
    _operationName = operationName;
    _vectorDataStr = vectorDataStr;
}

const char *VectorOperationException::what() const noexcept
{
    return std::string("Vector's operation '").append(_operationName).append("' is failed.\n")
           .append("Vector's data:\n")
           .append(_vectorDataStr).c_str();
}

// -------------------------- CommandExpired --------------------------- //

const char* CommandExpired::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
{
    return "Command is expired.";
}
