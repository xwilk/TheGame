#pragma once

#include "Math.hpp"
#include "Point.hpp"
#include "Circle.hpp"


class Projectile
{
public:
    Projectile(Point position, float rotation)
        : _position(position),
          _rotation(Math::ToRadians(rotation))
    {
    }

    void updatePosition(float deltaTime = 1.f);

    Point position() const;
    float rotation() const;
    Circle collisionArea() const;

    void takeDamage();
    bool isDead() const;

private:
    Point _position;
    float _rotation;
    int _speed = 12;
    float _collisionRadius = 2.f;
    int _hitpoints = 1;
};
