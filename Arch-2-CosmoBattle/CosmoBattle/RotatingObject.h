#ifndef ROTATINGOBJECT_H
#define ROTATINGOBJECT_H

#include "DataStructs.h"
#include "UObject.h"

class IRotatingObject
{
public:
    virtual Angle getAngle() const = 0;
    virtual Angle getAngularVelocity() const = 0;
    virtual void setAngle(const Angle &angle) = 0;
};

class RotatingObject : public IRotatingObject
{
public:
    RotatingObject(UObject *object);

    Angle getAngle() const override;
    Angle getAngularVelocity() const override;
    void setAngle(const Angle &angle) override;

private:
    UObject *_object = nullptr;

};

#endif // ROTATINGOBJECT_H
