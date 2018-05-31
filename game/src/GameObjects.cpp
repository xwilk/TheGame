#include "GameObjects.hpp"
#include "Collisions.hpp"


namespace
{

inline void makeWalls(std::vector<Wall>& walls, Width screenWidth)
{
    int x = 16, y = 16;
    while (x < screenWidth.get())
    {
        walls.emplace_back(Point{float(x), float(y)});
        x += 32;
    }
}

}

GameObjects::GameObjects()
{
    zombies.emplace_back(Point{500, 500});
    makeWalls(walls, SCREEN_WIDTH);
}

void GameObjects::update()
{
    player.updatePosition();

    for (auto& zombie : zombies)
    {
        zombie.updatePosition(player.position());
    }

    for (auto i = 0u; i < projectiles.size(); ++i)
    {
        auto& projectile = projectiles[i];
        projectile.updatePosition();

        for (auto j = 0u; j < zombies.size(); ++j)
        {
            auto& zombie = zombies[j];

            if (objectsCollide(projectile, zombie))
            {
                projectiles.erase(projectiles.begin() + i);
                zombie.takeDamage();

                if (zombie.isDead())
                {
                    zombies.erase(zombies.begin() + j);
                    player.score();
                }

                break;
            }
        }
    }

    spawnEnemies();
}

void GameObjects::spawnEnemies()
{
    auto playerScore = player.currentScore();
    if (playerScore > zombies.size())
    {
        auto x = playerScore % 2 == 0 ? 100.f : 540.f;
        auto y = zombies.size() % 2 == 0 ? 100.f : 380.f;
        zombies.emplace_back(Point{x, y});
    }
}
