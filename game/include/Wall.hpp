#pragma once

#include "Point.hpp"
#include "Rectangle.hpp"
#include "Dimensions.hpp"


class Wall
{
public:
    Wall(Point position)
        : _position(position)
    {}

    Point position()
    {
        return _position;
    }

    float rotation()
    {
        return 0.f;
    }

    Rectangle collisionArea()
    {
        return Rectangle(_position, _collisionWidth, _collisionHeight);
    }

private:
    Point _position;
    Width _collisionWidth{32};
    Height _collisionHeight{32};
};
