#pragma once

#include "Point.hpp"


class Zombie
{
public:
    void updatePosition(Point target, float deltaTime = 1.f);

    Point position() const;
    float rotation() const;

private:
    void rotateTowards(Point target);

    int _speed = 1;
    float _rotation = 0.0;
    Point _position{500, 500};
};
