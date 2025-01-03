#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "UObject.h"
#include <variant>

struct Vector
{
    int x = 0;
    int y = 0;
};

struct Angle
{
    float value;

    float getRad() const;
};

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
    MovingObject(IUObject *object);
    ~MovingObject() = default;

    Vector getLocation() override;
    void setLocation(const Vector &location) override;

    Vector getVelocity() override;

private:
    IUObject *_object = nullptr;

};

#endif // MOVINGOBJECT_H
