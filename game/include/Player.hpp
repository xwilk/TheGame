#pragma once

#include <memory>

#include "Point.hpp"
#include "Sidemove.hpp"

class InputPort;
class InputComponent;


class Player
{
public:
    Player(InputPort& inputPort);
    ~Player();
    void update();

    void updatePosition(float deltaTime = 1.f);

    Point position() const;
    float rotation() const;

    unsigned currentScore() const
    {
        return _score;
    }

    void score()
    {
        ++_score;
    }

    int speed = 0;

    int _sideSpeed = 0;
    float _rotation = 0.0;
    Point _position{100, 100};
    SIDEMOVE _sideMove = SIDEMOVE::NONE;
    unsigned _score = 0;

private:
    std::unique_ptr<InputComponent> _inputComponent;
};
