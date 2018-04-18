#pragma once

#include <vector>
#include "Sdl.hpp"
#include "FrameRate.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Dimensions.hpp"
#include "Projectile.hpp"

class Player;
class Zombie;
class Texture;


class Game
{
public:
    Game();

    void run();

private:
    void handleInput(Player&);
    void update(Player&, Zombie&);
    void draw(Texture&, Texture&, Texture&, Texture&, Player&, Zombie&);

    Sdl _sdl;
    FrameRate _frame;
    Window _window;
    Renderer _renderer;

    bool _isRunning = true;

    std::vector<Projectile> _projectiles;
};
