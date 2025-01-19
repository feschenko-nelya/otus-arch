#ifndef UOBJECT_H
#define UOBJECT_H

#include <any>
#include <string>
#include <unordered_map>
#include <set>

class IUObject
{
public:
    virtual std::any getProperty(const std::string &name) const = 0;
    virtual void setProperty(const std::string &name, const std::any &value) = 0;

};

class UObject : public IUObject
{
public:
    UObject() = default;
    virtual ~UObject() = default;

    std::any getProperty(const std::string &name) const override;
    void setProperty(const std::string &name, const std::any &value) override;

protected:
    bool hasProperty(const std::string &name) const;
    int getPropertiesCount() const;
    std::set<std::string> getPropertiesNames() const;

private:
    std::unordered_map<std::string, std::any> _properties;

};

#endif // UOBJECT_H
