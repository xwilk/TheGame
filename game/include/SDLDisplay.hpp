#pragma once

#include <map>
#include <vector>
#include <memory>
#include <stdexcept>
#include <SDL.h>

#include "Sdl.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"

class Player;
class Zombie;
class Wall;
class Projectile;
struct GameObjects;

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

    void clear();
    void apply(GameObjects&);
    void renderPresent();

private:
    Sdl _sdl;
    Window _window;
    Renderer _renderer;
    std::map<GameObjectId, std::unique_ptr<Texture>> _textures;
};
