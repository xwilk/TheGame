#pragma once

#include <map>
#include <vector>
#include <memory>
#include <stdexcept>
#include <SDL.h>

class Texture;
class Window;
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

class RendererError : public std::runtime_error
{
public:
    RendererError(const std::string& what_arg)
        : std::runtime_error(what_arg)
    {}
};

class Renderer
{
public:
    Renderer(Window&);
    ~Renderer();

    void apply(
        Player&,
        std::vector<Zombie>&,
        std::vector<Wall>&,
        std::vector<Projectile>&);

    operator SDL_Renderer*()
    {
        return _renderer;
    }

private:
    SDL_Renderer* _renderer;
    std::map<GameObjectId, std::unique_ptr<Texture>> _textures;
};
