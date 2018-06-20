#include "MoveComponent.hpp"
#include "Player.hpp"


void MoveComponent::update(Player& player, float deltaTime)
{
    auto rotationInRadians = Math::ToRadians(player.rotation);

    auto sideMoveVector = Vector2::getForwardVector(
        rotationInRadians + Math::ToRadians(static_cast<float>(player.sideMove)));

    if (player.speed != 0)
    {
        auto forwardVector = Vector2::getForwardVector(rotationInRadians);
        sideMoveVector = (forwardVector + sideMoveVector) / 2;
        player.position += sideMoveVector * player.speed * deltaTime;
    }
    else
    {
        player.position += sideMoveVector * player.sideSpeed * deltaTime;
    }

    player.speed = 0;
    player.sideSpeed = 0;
    player.sideMove = SIDEMOVE::NONE;
}
