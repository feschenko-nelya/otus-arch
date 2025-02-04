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

bool UObject::hasProperty(const std::string &name) const
{
    return (_properties.find(name) != _properties.end());
}

int UObject::getPropertiesCount() const
{
    return static_cast<int>(_properties.size());
}

std::set<std::string> UObject::getPropertiesNames() const
{
    std::set<std::string> names;

    for (auto it = _properties.cbegin(); it != _properties.cend(); ++it)
    {
        names.insert(it->first);
    }

    return names;
}
