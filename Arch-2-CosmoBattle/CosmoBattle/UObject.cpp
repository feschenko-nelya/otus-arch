#include "UObject.h"

#include "UObjectException.h"

std::any UObject::getProperty(const std::string &name) const
{
    auto it = _properties.find(name);

    if (it == _properties.end())
    {
        throw UObjectAbsentPropertyException(name);
    }

    return it->second;
}

void UObject::setProperty(const std::string &name, const std::any &value)
{
    _properties[name] = value;
}

int UObject::getPropertyInt(const std::string &name) const
{
    return std::any_cast<int>(getProperty(name));
}
