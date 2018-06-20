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

