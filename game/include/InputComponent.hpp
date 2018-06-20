#pragma once

#include "InputPort.hpp"

class Player;


class InputComponent
{
public:
    InputComponent(InputPort& inputPort)
        : _inputPort(inputPort)
    {}

    void update(Player& player)
    {
        while (not _inputPort.empty())
        {
            auto msg = _inputPort.pop();
            switch (msg.id)
            {
                case InputMsgId::INCREASE_SPEED: increaseSpeed(player); break;
                case InputMsgId::DECREASE_SPEED: decreaseSpeed(player); break;
                case InputMsgId::SIDEMOVE_LEFT: useSideMove(player, SIDEMOVE::LEFT); break;
                case InputMsgId::SIDEMOVE_RIGHT: useSideMove(player, SIDEMOVE::RIGHT); break;
                case InputMsgId::ROTATE: rotate(player, msg.payload.rotateTowards.target); break;
                default: break;
            }
        }
    }

private:
    void increaseSpeed(Player& player)
    {
        player.speed = 2;
    }

    void decreaseSpeed(Player& player)
    {
        player.speed = -1;
    }

    void useSideMove(Player& player, SIDEMOVE option)
    {
        player.sideMove = option;
        player.sideSpeed = 1.4;
    }

    void rotate(Player& player, Point target)
    {
        auto vectorBetweenPoints = target - player._position;
        vectorBetweenPoints.Normalize();

        player._rotation = Math::Atan2(vectorBetweenPoints.x, -vectorBetweenPoints.y);
    }

    InputPort& _inputPort;
};
