#include "MoveComponent.hpp"
#include "Player.hpp"


void MoveComponent::update(Player& player, float deltaTime)
{
    auto sideMoveVector = Vector2::getForwardVector(
        player._rotation + Math::ToRadians(static_cast<float>(player._sideMove)));

    if (player.speed != 0)
    {
        auto forwardVector = Vector2::getForwardVector(player._rotation);
        sideMoveVector = (forwardVector + sideMoveVector) / 2;
        player._position += sideMoveVector * player.speed * deltaTime;
    }
    else
    {
        player._position += sideMoveVector * player._sideSpeed * deltaTime;
    }

    player.speed = 0;
    player._sideSpeed = 0;
    player._sideMove = SIDEMOVE::NONE;
}
