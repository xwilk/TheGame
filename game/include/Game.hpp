#pragma once

#include <vector>
#include "FrameRate.hpp"
#include "SDLDisplay.hpp"
#include "Dimensions.hpp"
#include "Projectile.hpp"
#include "Zombie.hpp"
#include "Wall.hpp"

class Player;


class Game
{
public:
    Game();

    void run();

private:
    void handleInput(Player&);
    void update(Player&);
    void draw(Player&);

    void spawnEnemies(unsigned playerScore);

    FrameRate _frame;
    SDLDisplay _display;

    bool _isRunning = true;

    std::vector<Projectile> _projectiles;
    std::vector<Zombie> _zombies;
    std::vector<Wall> _walls;
};
