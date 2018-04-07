#include "Player.hpp"


void Player::increaseSpeed()
{
    _speed = 2;
}

void Player::decreaseSpeed()
{
    _speed = 0;
}

void Player::rotateTowards(Point point)
{
    auto target = Vector2(point.x, point.y);
    auto pos = Vector2(_position.x, _position.y);

    auto vectorBetweenPoints = target - pos;
    vectorBetweenPoints.Normalize();

    _forwardUnitVector = vectorBetweenPoints;
    _rotation = Math::ToDegrees(Math::Atan2(vectorBetweenPoints.x, -vectorBetweenPoints.y));
}

void Player::updatePosition(float deltaTime)
{
    if (!Math::NearZero(_speed))
    {
        auto pos = Vector2(_position.x, _position.y);
        pos += _forwardUnitVector * _speed * deltaTime;
        _position = Point(pos.x, pos.y);
    }

    decreaseSpeed();
}

Point Player::position() const
{
    return _position;
}

float Player::rotation() const
{
    return _rotation;
}