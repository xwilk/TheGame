#pragma once

#include <vector>

#include "Player.hpp"
#include "Projectile.hpp"
#include "Wall.hpp"
#include "Zombie.hpp"
#include "Consts.hpp"


inline void makeWalls(std::vector<Wall>& walls, Width screenWidth)
{
    int x = 16, y = 16;
    while (x < screenWidth.get())
    {
        walls.emplace_back(Point{float(x), float(y)});
        x += 32;
    }
}

struct GameObjects
{
    GameObjects()
    {
        zombies.emplace_back(Point{500, 500});
        makeWalls(walls, SCREEN_WIDTH);
    }

    void spawnEnemies()
    {
        auto playerScore = player.currentScore();
        if (playerScore > zombies.size())
        {
            auto x = playerScore % 2 == 0 ? 100.f : 540.f;
            auto y = zombies.size() % 2 == 0 ? 100.f : 380.f;
            zombies.emplace_back(Point{x, y});
        }
    }

    Player player{};
    std::vector<Projectile> projectiles{};
    std::vector<Zombie> zombies{};
    std::vector<Wall> walls{};
};
