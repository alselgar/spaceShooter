#include "Direction.h"

Direction::Direction(float angle, float distance)
{
    this->angle = angle;
    this->distance = distance;
}

Direction::~Direction()
{
    //dtor
}

float Direction::getAngle() {
    return angle;
}

float Direction::getAngleInRadians() {
    return (angle * M_PI / 180.0);
}

float Direction::getDistance() {
    return distance;
}
