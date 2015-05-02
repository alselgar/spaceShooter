#ifndef DIRECTION_H
#define DIRECTION_H
#include <math.h>


class Direction
{
    public:
        Direction();
        Direction(float angle, float distance);
        virtual ~Direction();
        float getAngle();
        float getAngleInRadians();
        float getDistance();
    private:
        float angle;
        float distance;
};

#endif // DIRECTION_H
