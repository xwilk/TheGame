#include "Renderer.hpp"
#include "Window.hpp"
#include "Texture.hpp"
#include "ResourcePath.hpp"
#include "Player.hpp"
#include "Zombie.hpp"
#include "Wall.hpp"
#include "Projectile.hpp"

const auto SCREEN_WIDTH = Width{640};
const auto SCREEN_HEIGHT = Height{480};
const auto SPRITE_WIDTH = Width{32};
const auto SPRITE_HEIGHT = Height{32};
const int TILE_SIZE = 128;
const auto BULLET_WIDTH = Width{2};
const auto BULLET_HEIGHT = Height{8};


Renderer::Renderer(Window& window)
{
    _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (not _renderer)
        throw RendererError("CreateRenderer");

    _textures[GameObjectId::PLAYER] = std::make_unique<Texture>(
        getResourcePath("game") + "man.png",
        _renderer,
        SPRITE_WIDTH,
        SPRITE_HEIGHT,
        Grid{Width{1}, Height{1}});

    _textures[GameObjectId::ZOMBIE] = std::make_unique<Texture>(
        getResourcePath("game") + "zombie.png",
        _renderer,
        SPRITE_WIDTH,
        SPRITE_HEIGHT,
        Grid{Width{1}, Height{1}});

    _textures[GameObjectId::BULLET] = std::make_unique<Texture>(
        getResourcePath("game") + "bullet.png",
        _renderer,
        BULLET_WIDTH,
        BULLET_HEIGHT,
        Grid{Width{1}, Height{1}});

    _textures[GameObjectId::WALL] = std::make_unique<Texture>(
        getResourcePath("game") + "wall.png",
        _renderer,
        SPRITE_WIDTH,
        SPRITE_HEIGHT,
        Grid{Width{1}, Height{1}});

    _textures[GameObjectId::BACKGROUND] = std::make_unique<Texture>(
        getResourcePath("game") + "tex.png",
        _renderer,
        Width{TILE_SIZE},
        Height{TILE_SIZE},
        Grid{Width{1}, Height{1}});
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(_renderer);
}

void Renderer::apply(
    Player& player,
    std::vector<Zombie>& zombies,
    std::vector<Wall>& walls,
    std::vector<Projectile>& projectiles)
{
    _textures[GameObjectId::BACKGROUND]->tile(
        *this,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        TILE_SIZE);

    _textures[GameObjectId::PLAYER]->render(
        *this,
        player.position(),
        player.rotation());

    for (auto& zombie : zombies)
    {
        _textures[GameObjectId::ZOMBIE]->render(
            *this,
            zombie.position(),
            zombie.rotation());
    }

    for (auto& wall : walls)
    {
        _textures[GameObjectId::WALL]->render(
            *this,
            wall.position(),
            wall.rotation());
    }

    for (auto& projectile : projectiles)
    {
        _textures[GameObjectId::BULLET]->render(
            *this,
            projectile.position(),
            projectile.rotation());
    }
}