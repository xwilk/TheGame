#include <iostream>
#include <SDL.h>

#include "Game.hpp"
#include "Texture.hpp"
#include "ResourcePath.hpp"

const auto SCREEN_WIDTH = Width{640};
const auto SCREEN_HEIGHT = Height{480};
const int TILE_SIZE = 32;
const auto SPRITE_WIDTH = Width{128};
const auto SPRITE_HEIGHT = Height{128};



Game::Game()
    : _window(Width{SCREEN_WIDTH}, Height{SCREEN_HEIGHT}),
      _renderer(_window)
{
}

void Game::run()
{
    auto image = Texture(
        getResourcePath("game") + "hello_grid.png",
        _renderer,
        SPRITE_WIDTH,
        SPRITE_HEIGHT,
        Grid{Width{2}, Height{2}});

    auto background = Texture(
        getResourcePath("game") + "nk_flag.bmp",
        _renderer,
        Width{TILE_SIZE},
        Height{TILE_SIZE},
        Grid{Width{1}, Height{1}});

    SDL_Event e;
    bool quit = false;
    int x = 100, y = 100;
    int counter = 0;
    double rotation = 0.0;

    while (!quit)
    {
        _frame.start();
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
        if (currentKeyStates[SDL_SCANCODE_DOWN])
        {
            y += 10;
            counter++;
            ++rotation;
        }

        if (currentKeyStates[SDL_SCANCODE_UP])
        {
            y -= 10;
            counter++;
            ++rotation;
        }

        if (currentKeyStates[SDL_SCANCODE_LEFT])
        {
            x -= 10;
            counter++;
            ++rotation;
        }

        if (currentKeyStates[SDL_SCANCODE_RIGHT])
        {
            x += 10;
            counter++;
            ++rotation;
        }

        SDL_RenderClear(_renderer);
        background.tile(_renderer, SCREEN_WIDTH, SCREEN_HEIGHT, TILE_SIZE);

        if (counter > 3)
        {
            image.nextClip();
            counter = 0;
        }

        image.render(_renderer, x, y, rotation);
        SDL_RenderPresent(_renderer);

        _frame.delay();
    }
}
