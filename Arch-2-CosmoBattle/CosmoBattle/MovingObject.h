#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "UObject.h"
#include "DataStructs.h"

#include <memory>
#include <variant>

class IMovingObject
{
public:
    virtual Vector getLocation() = 0;
    virtual void setLocation(const Vector &location) = 0;

    virtual Vector getVelocity() = 0;
};

class MovingObject : public IMovingObject
{
public:
    MovingObject(std::shared_ptr<IUObject> object);
    ~MovingObject() = default;

    Vector getLocation() override;
    void setLocation(const Vector &location) override;

    Vector getVelocity() override;

private:
    std::weak_ptr<IUObject> _object;

};

#endif // MOVINGOBJECT_H
