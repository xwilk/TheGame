#pragma once

#include <memory>

#include "Point.hpp"
#include "Sidemove.hpp"

class InputPort;
class InputComponent;
class MoveComponent;


class Player
{
public:
    Player(InputPort& inputPort);
    ~Player();
    void update();

    float rotation() const;

    int speed = 0;
    int sideSpeed = 0;
    SIDEMOVE sideMove = SIDEMOVE::NONE;

    float _rotation = 0.0;
    Point position{100, 100};

private:
    std::unique_ptr<InputComponent> _inputComponent;
    std::unique_ptr<MoveComponent> _moveComponent;
};
