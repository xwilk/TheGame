#include <algorithm>

#include "GameObjects.hpp"
#include "Collisions.hpp"


GameObjects::GameObjects(InputPort& inputPort)
    : player(inputPort)
{
    zombies.emplace_back(Point{500, 500});
}

void GameObjects::update()
{
    player.update();
    player.updatePosition();

    for (auto& zombie : zombies)
    {
        zombie.updatePosition(player.position());
    }

    for (auto& projectile : projectiles)
    {
        projectile.updatePosition();

        for (auto& zombie : zombies)
        {
            if (objectsCollide(projectile, zombie))
            {
                projectile.takeDamage();
                zombie.takeDamage();
                break;
            }
        }
    }

    cleanUp();
    spawnEnemies();
}

void GameObjects::cleanUp()
{
    auto isDead = [](const auto& object) { return object.isDead(); };

    using namespace std;

    zombies.erase(
        remove_if(begin(zombies), end(zombies), isDead),
        end(zombies));

    projectiles.erase(
        remove_if(begin(projectiles), end(projectiles), isDead),
        end(projectiles));
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
