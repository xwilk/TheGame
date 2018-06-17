#include "Player.hpp"
#include "InputComponent.hpp"
#include "Math.hpp"


Player::Player(InputPort& inputPort)
    : _inputComponent(std::make_unique<InputComponent>(inputPort))
{}

Player::~Player()
{
}

void Player::update()
{
    _inputComponent->update(*this);
}

void Player::updatePosition(float deltaTime)
{
    auto sideMoveVector = Vector2::getForwardVector(
        _rotation + Math::ToRadians(static_cast<float>(_sideMove)));

    if (speed != 0)
    {
        auto forwardVector = Vector2::getForwardVector(_rotation);
        sideMoveVector = (forwardVector + sideMoveVector) / 2;
        _position += sideMoveVector * speed * deltaTime;
    }
    else
    {
        _position += sideMoveVector * _sideSpeed * deltaTime;
    }

    speed = 0;
    _sideSpeed = 0;
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