#pragma once

#include "Texture.hpp"
#include "Point.hpp"
#include "Math.hpp"


enum class SIDEMOVE
{
    NONE = 0,
    LEFT = -90,
    RIGHT = 90
};

class Player
{
public:
    void increaseSpeed();
    void decreaseSpeed();
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

private:
    int _speed = 0;
    float _rotation = 0.0;
    Point _forwardUnitVector = {};
    Point _position{100, 100};
    SIDEMOVE _sideMove = SIDEMOVE::NONE;
    unsigned _score = 0;
};