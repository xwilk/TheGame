#include <iostream>
#include <SDL.h>

#include "Game.hpp"
#include "Player.hpp"
#include "Texture.hpp"
#include "ResourcePath.hpp"
#include "Point.hpp"

const auto SCREEN_WIDTH = Width{640};
const auto SCREEN_HEIGHT = Height{480};
const int TILE_SIZE = 128;
const auto SPRITE_WIDTH = Width{32};
const auto SPRITE_HEIGHT = Height{32};


Game::Game()
    : _window(Width{SCREEN_WIDTH}, Height{SCREEN_HEIGHT}),
      _renderer(_window)
{
}

void Game::run()
{
    auto player = Player{};

    auto image = Texture(
        getResourcePath("game") + "man.png",
        _renderer,
        SPRITE_WIDTH,
        SPRITE_HEIGHT,
        Grid{Width{2}, Height{2}});

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
        player.updatePosition();

        SDL_RenderClear(_renderer);
        background.tile(_renderer, SCREEN_WIDTH, SCREEN_HEIGHT, TILE_SIZE);
        image.render(_renderer, player.position(), player.rotation());
        SDL_RenderPresent(_renderer);

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
