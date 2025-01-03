#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

struct Vector
{
    int x = 0;
    int y = 0;
};

struct Angle
{
    float value;

    float getRad() const;
    Angle plus(const Angle &angle);
};

#endif // DATASTRUCTS_H
