#pragma once

#include "Point.hpp"


class Zombie
{
public:
    Zombie(Point position)
        : _position(position)
    {}

    void updatePosition(Point target, float deltaTime = 1.f);

    Point position() const;
    float rotation() const;

    float collisionRadius() const
    {
        return _collisionRadius;
    }

    void takeDamage()
    {
        if (not --_hitpoints)
        {
            _speed = 0;
            _collisionRadius = 0.f;
        }
    }

    bool isDead()
    {
        return _hitpoints < 1;
    }

private:
    void rotateTowards(Point target);

    int _speed = 1;
    float _rotation = 0.0;
    Point _position{500, 500};
    float _collisionRadius = 16.f;
    int _hitpoints{5};
};
