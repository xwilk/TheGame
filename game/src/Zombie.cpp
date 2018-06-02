#include "Zombie.hpp"
#include "Math.hpp"


void Zombie::updatePosition(Point target, float deltaTime)
{
    rotateTowards(target);

    if (!Math::NearZero(_speed))
    {
        auto forwardVector = Vector2::getForwardVector(_rotation);
        _position += forwardVector * _speed * deltaTime;
    }
}

void Zombie::rotateTowards(Point target)
{
    auto vectorBetweenPoints = target - _position;
    vectorBetweenPoints.Normalize();

    _rotation = Math::Atan2(vectorBetweenPoints.x, -vectorBetweenPoints.y);
}

Point Zombie::position() const
{
    return _position;
}

float Zombie::rotation() const
{
    return Math::ToDegrees(_rotation);
}

Circle Zombie::collisionArea() const
{
    return Circle{_collisionRadius, _position};
}

void Zombie::takeDamage()
{
    --_hitpoints;
}

bool Zombie::isDead() const
{
    return _hitpoints < 1;
}
