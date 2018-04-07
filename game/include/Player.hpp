#pragma once

#include "Texture.hpp"
#include "Point.hpp"
#include "Math.hpp"


class Player
{
public:
    void increaseSpeed();
    void decreaseSpeed();
    void rotateTowards(Point);

    void updatePosition(float deltaTime = 1.f);


    Point position() const;
    float rotation() const;

private:
    int _speed = 0;
    float _rotation = 0.0;
    Vector2 _forwardUnitVector = {};
    Point _position{100, 100};
};