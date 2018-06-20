#pragma once

#include "InputPort.hpp"

class Player;


class InputComponent
{
public:
    InputComponent(InputPort& inputPort);
    void update(Player& player);

private:
    InputPort& _inputPort;
};
