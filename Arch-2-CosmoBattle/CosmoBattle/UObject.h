#ifndef UOBJECT_H
#define UOBJECT_H

#include <any>
#include <string>
#include <unordered_map>

class UObject
{
public:
    UObject() = default;
    ~UObject() = default;

    std::any getProperty(const std::string &name) const;
    void setProperty(const std::string &name, const std::any &value);

    int getPropertyInt(const std::string &name) const;

private:
    std::unordered_map<std::string, std::any> _properties;

};

#endif // UOBJECT_H
