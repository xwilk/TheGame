#include <iostream>
#include <SDL.h>

#include "Game.hpp"
#include "Player.hpp"
#include "Zombie.hpp"
#include "Texture.hpp"
#include "ResourcePath.hpp"
#include "Point.hpp"

const auto SCREEN_WIDTH = Width{640};
const auto SCREEN_HEIGHT = Height{480};
const int TILE_SIZE = 128;
const auto SPRITE_WIDTH = Width{32};
const auto SPRITE_HEIGHT = Height{32};
const auto BULLET_WIDTH = Width{2};
const auto BULLET_HEIGHT = Height{8};


Game::Game()
    : _window(Width{SCREEN_WIDTH}, Height{SCREEN_HEIGHT}),
      _renderer(_window)
{
}

void Game::run()
{
    auto player = Player{};
    auto zombie = Zombie{};

    auto image = Texture(
        getResourcePath("game") + "man.png",
        _renderer,
        SPRITE_WIDTH,
        SPRITE_HEIGHT,
        Grid{Width{1}, Height{1}});

    auto zombieImage = Texture(
        getResourcePath("game") + "zombie.png",
        _renderer,
        SPRITE_WIDTH,
        SPRITE_HEIGHT,
        Grid{Width{1}, Height{1}});

    auto bulletImage = Texture(
        getResourcePath("game") + "bullet.png",
        _renderer,
        BULLET_WIDTH,
        BULLET_HEIGHT,
        Grid{Width{1}, Height{1}});

    auto background = Texture(
        getResourcePath("game") + "tex.png",
        _renderer,
        Width{TILE_SIZE},
        Height{TILE_SIZE},
        Grid{Width{1}, Height{1}});

    while (_isRunning)
    {
        _frame.start();

        handleInput(player);
        update(player, zombie);
        draw(background, image, zombieImage, bulletImage, player, zombie);

        _frame.delay();
    }
}

void Game::handleInput(Player& player)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            _isRunning = false;
        }

        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            _projectiles.emplace_back(player.position(), player.rotation());
        }
    }

    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if (currentKeyStates[SDL_SCANCODE_W])
    {
        player.increaseSpeed();
    }

    if (currentKeyStates[SDL_SCANCODE_S])
    {
        player.decreaseSpeed();
    }

    if (currentKeyStates[SDL_SCANCODE_A])
    {
        player.useSideMove(SIDEMOVE::LEFT);
        player.increaseSpeed();
    }

    if (currentKeyStates[SDL_SCANCODE_D])
    {
        player.useSideMove(SIDEMOVE::RIGHT);
        player.increaseSpeed();
    }

    int mouse_x = 0, mouse_y = 0;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    player.rotateTowards(Point(mouse_x, mouse_y));
}

void Game::update(Player& player, Zombie& zombie)
{
    player.updatePosition();
    zombie.updatePosition(player.position());

    for (auto& projectile : _projectiles)
    {
        projectile.updatePosition();
    }
}

void Game::draw(
    Texture& background,
    Texture& image,
    Texture& zombieImage,
    Texture& bulletImage,
    Player& player,
    Zombie& zombie)
{
    SDL_RenderClear(_renderer);
    background.tile(_renderer, SCREEN_WIDTH, SCREEN_HEIGHT, TILE_SIZE);
    image.render(_renderer, player.position(), player.rotation());
    zombieImage.render(_renderer, zombie.position(), zombie.rotation());

    for (auto& projectile : _projectiles)
    {
        bulletImage.render(_renderer, projectile.position(), projectile.rotation());
    }

    SDL_RenderPresent(_renderer);
}
