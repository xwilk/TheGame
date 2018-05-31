#pragma once

#include <map>
#include <vector>
#include <memory>
#include <stdexcept>
#include <SDL.h>

#include "Sdl.hpp"
#include "Window.hpp"
#include "Renderer.hpp"

class Texture;
class Player;
class Zombie;
class Wall;
class Projectile;

enum class GameObjectId
{
    BACKGROUND,
    PLAYER,
    ZOMBIE,
    BULLET,
    WALL
};

class SDLDisplay
{
public:
    SDLDisplay();
    ~SDLDisplay();

    void clear();

    void apply(
        Player&,
        std::vector<Zombie>&,
        std::vector<Wall>&,
        std::vector<Projectile>&);

    void renderPresent();

private:
    Sdl _sdl;
    Window _window;
    Renderer _renderer;
    std::map<GameObjectId, std::unique_ptr<Texture>> _textures;
};
