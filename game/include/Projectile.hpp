#pragma once

#include "Math.hpp"
#include "Point.hpp"


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

    float collisionRadius() const
    {
        return _collisionRadius;
    }

private:
    Point _position;
    float _rotation;
    int _speed = 3;
    float _collisionRadius = 2.f;
};
