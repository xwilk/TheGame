#pragma once

#include <vector>
#include "Sdl.hpp"
#include "FrameRate.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Dimensions.hpp"
#include "Projectile.hpp"
#include "Zombie.hpp"
#include "Wall.hpp"

class Player;
class Texture;


class Game
{
public:
    Game();

    void run();

private:
    void handleInput(Player&);
    void update(Player&);
    void draw(Texture&, Texture&, Texture&, Texture&, Texture&, Player&);

    void spawnEnemies(unsigned playerScore);

    Sdl _sdl;
    FrameRate _frame;
    Window _window;
    Renderer _renderer;

    bool _isRunning = true;

    std::vector<Projectile> _projectiles;
    std::vector<Zombie> _zombies;
    std::vector<Wall> _walls;
};
