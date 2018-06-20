#pragma once

class Player;


class MoveComponent
{
public:
    void update(Player&, float deltaTime = 1.f);
};
