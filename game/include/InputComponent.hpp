#pragma once

// #include "Player.hpp"
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

    InputPort& _inputPort;
};
