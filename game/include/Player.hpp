#pragma once

#include <memory>

#include "Texture.hpp"
#include "Point.hpp"
#include "Math.hpp"

class InputPort;
class InputComponent;


enum class SIDEMOVE
{
    NONE = 0,
    LEFT = -90,
    RIGHT = 90
};

class Player
{
public:
    Player(InputPort& inputPort);
    ~Player();
    void update();

    void rotateTowards(Point);
    void useSideMove(SIDEMOVE);

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
    Point _forwardUnitVector{0, 0};
    SIDEMOVE _sideMove = SIDEMOVE::NONE;
    unsigned _score = 0;

private:
    std::unique_ptr<InputComponent> _inputComponent;
};
