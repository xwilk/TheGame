#pragma once

#include <vector>

#include "Player.hpp"
#include "Projectile.hpp"
#include "Wall.hpp"
#include "Zombie.hpp"
#include "Consts.hpp"
#include "Collisions.hpp"


struct GameObjects
{
    Player player{};
    std::vector<Projectile> projectiles{};
    std::vector<Zombie> zombies{};
    std::vector<Wall> walls{};

    GameObjects();

    void update();

private:
    void spawnEnemies();
};
