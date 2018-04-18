#include "Player.hpp"


void Player::increaseSpeed()
{
    _speed = 2;
}

void Player::decreaseSpeed()
{
    _speed = -1;
}

void Player::rotateTowards(Point target)
{
    auto vectorBetweenPoints = target - _position;
    vectorBetweenPoints.Normalize();

    _forwardUnitVector = vectorBetweenPoints;
    _rotation = Math::Atan2(vectorBetweenPoints.x, -vectorBetweenPoints.y);
}

void Player::useSideMove(SIDEMOVE option)
{
    _sideMove = option;
}

void Player::updatePosition(float deltaTime)
{
    if (!Math::NearZero(_speed))
    {
        auto forwardVector = Vector2::getForwardVector(_rotation);

        if (_sideMove != SIDEMOVE::NONE)
        {
            auto sideMoveVector = Vector2::getForwardVector(
                _rotation + Math::ToRadians(static_cast<float>(_sideMove)));

            forwardVector = (forwardVector + sideMoveVector) / 2;
        }

        _position += forwardVector * _speed * deltaTime;
    }

    _speed = 0;
    _sideMove = SIDEMOVE::NONE;
}

Point Player::position() const
{
    return _position;
}

float Player::rotation() const
{
    return Math::ToDegrees(_rotation);
}