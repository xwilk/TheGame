#include "Player.hpp"
#include "InputComponent.hpp"
#include "MoveComponent.hpp"
#include "Math.hpp"


Player::Player(InputPort& inputPort)
    : _inputComponent(std::make_unique<InputComponent>(inputPort)),
      _moveComponent(std::make_unique<MoveComponent>())
{}

Player::~Player()
{
}

void Player::update()
{
    _inputComponent->update(*this);
    _moveComponent->update(*this);
}

Point Player::position() const
{
    return _position;
}

float Player::rotation() const
{
    return Math::ToDegrees(_rotation);
}