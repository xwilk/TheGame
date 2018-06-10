#pragma once

#include <vector>

#include "Player.hpp"
#include "Projectile.hpp"
#include "Wall.hpp"
#include "Zombie.hpp"
#include "Consts.hpp"

class InputPort;


struct GameObjects
{
    GameObjects(InputPort& inputPort);

    Player player;
    std::vector<Projectile> projectiles;
    std::vector<Zombie> zombies;
    GameObjects();

    void update();

private:
    void spawnEnemies();
    void cleanUp();
};
