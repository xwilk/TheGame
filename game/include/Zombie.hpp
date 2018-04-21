#pragma once

#include "Point.hpp"
#include "Circle.hpp"


class Zombie
{
public:
    Zombie(Point position)
        : _position(position)
    {}

    void updatePosition(Point target, float deltaTime = 1.f);

    Point position() const;
    float rotation() const;
    Circle collisionArea() const;

    void takeDamage();
    bool isDead();

private:
    void rotateTowards(Point target);

    float _speed = 0.5f;
    float _rotation = 0.0;
    float _collisionRadius = 16.f;
    int _hitpoints{5};

    Point _position;
};
