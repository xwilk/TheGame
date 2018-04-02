#include <iostream>
#include <SDL.h>

#include "Game.hpp"
#include "Texture.hpp"
#include "ResourcePath.hpp"

const auto SCREEN_WIDTH = Width{640};
const auto SCREEN_HEIGHT = Height{480};
const int TILE_SIZE = 32;
const int SPRITE_WIDTH = 128;



Game::Game()
    : _window(Width{SCREEN_WIDTH}, Height{SCREEN_HEIGHT}),
      _renderer(_window)
{
}

void Game::run()
{
    auto image = Texture(getResourcePath("game") + "hello_grid.png", _renderer);
    auto background = Texture(getResourcePath("game") + "nk_flag.bmp", _renderer);

    SDL_Event e;
    bool quit = false;
    int x = 100, y = 100;
    int counter = 0;
    double rotation = 0.0;

    SDL_Rect clips[4];
    for (auto i = 0; i < 4; ++i)
    {
        auto& c = clips[i];
        c.x = i % 2 * SPRITE_WIDTH;
        c.y = i / 2 * SPRITE_WIDTH;
        c.w = SPRITE_WIDTH;
        c.h = SPRITE_WIDTH;
    }

    int useClip = 0;

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

        useClip = counter / 3;
        if (useClip > 3)
        {
            useClip = 0;
            counter = 0;
        }

        image.render(_renderer, x, y, &clips[useClip], rotation);
        SDL_RenderPresent(_renderer);

        _frame.delay();
    }
}
