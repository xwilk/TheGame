#include "Projectile.hpp"


void Projectile::updatePosition(float deltaTime)
{
    if (!Math::NearZero(_speed))
    {
        auto forwardVector = Vector2::getForwardVector(_rotation);
        _position += forwardVector * _speed * deltaTime;
    }
}

Point Projectile::position() const
{
    return _position;
}

float Projectile::rotation() const
{
    return Math::ToDegrees(_rotation);
}
