#include <SDL.h>

#include "SDLDisplay.hpp"
#include "ResourcePath.hpp"
#include "Player.hpp"
#include "Zombie.hpp"
#include "Wall.hpp"
#include "Projectile.hpp"
#include "Consts.hpp"
#include "GameObjects.hpp"


SDLDisplay::SDLDisplay()
    : _sdl(),
      _window(Width{SCREEN_WIDTH}, Height{SCREEN_HEIGHT}),
      _renderer(_window)
{
    _textures[GameObjectType::PLAYER] = std::make_unique<Texture>(
        getResourcePath("game") + "man.png",
        _renderer,
        SPRITE_WIDTH,
        SPRITE_HEIGHT,
        Grid{Width{1}, Height{1}});

    _textures[GameObjectType::ZOMBIE] = std::make_unique<Texture>(
        getResourcePath("game") + "zombie.png",
        _renderer,
        SPRITE_WIDTH,
        SPRITE_HEIGHT,
        Grid{Width{1}, Height{1}});

    _textures[GameObjectType::BULLET] = std::make_unique<Texture>(
        getResourcePath("game") + "bullet.png",
        _renderer,
        BULLET_WIDTH,
        BULLET_HEIGHT,
        Grid{Width{1}, Height{1}});

    _textures[GameObjectType::WALL] = std::make_unique<Texture>(
        getResourcePath("game") + "wall.png",
        _renderer,
        SPRITE_WIDTH,
        SPRITE_HEIGHT,
        Grid{Width{1}, Height{1}});

    _textures[GameObjectType::BACKGROUND] = std::make_unique<Texture>(
        getResourcePath("game") + "tex.png",
        _renderer,
        Width{TILE_SIZE},
        Height{TILE_SIZE},
        Grid{Width{1}, Height{1}});
}

void SDLDisplay::clear()
{
    SDL_RenderClear(_renderer);
}

void SDLDisplay::apply(GameObjects& gameObjects)
{
    _textures[GameObjectType::BACKGROUND]->tile(
        _renderer,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        TILE_SIZE);

    _textures[GameObjectType::PLAYER]->render(
        _renderer,
        gameObjects.player.position,
        gameObjects.player.rotation);

    for (auto& zombie : gameObjects.zombies)
    {
        _textures[GameObjectType::ZOMBIE]->render(
            _renderer,
            zombie.position(),
            zombie.rotation());
    }

    for (auto& projectile : gameObjects.projectiles)
    {
        _textures[GameObjectType::BULLET]->render(
            _renderer,
            projectile.position(),
            projectile.rotation());
    }
}

void SDLDisplay::renderPresent()
{
    SDL_RenderPresent(_renderer);
}