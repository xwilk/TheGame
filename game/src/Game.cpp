#include <iostream>
#include <SDL.h>

#include "Game.hpp"


Game::Game()
    : _display()
{
}

void Game::run()
{
    while (_isRunning)
    {
        _frame.start();

        handleInput();
        update();
        draw();

        _frame.delay();
    }
}

void Game::handleInput()
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
            _gameObjects.projectiles.emplace_back(
                _gameObjects.player.position(),
                _gameObjects.player.rotation());
        }
    }

    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if (currentKeyStates[SDL_SCANCODE_W])
    {
        _gameObjects.player.increaseSpeed();
    }

    if (currentKeyStates[SDL_SCANCODE_S])
    {
        _gameObjects.player.decreaseSpeed();
    }

    if (currentKeyStates[SDL_SCANCODE_A])
    {
        _gameObjects.player.useSideMove(SIDEMOVE::LEFT);
    }

    if (currentKeyStates[SDL_SCANCODE_D])
    {
        _gameObjects.player.useSideMove(SIDEMOVE::RIGHT);
    }

    int mouse_x = 0, mouse_y = 0;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    _gameObjects.player.rotateTowards(Point(mouse_x, mouse_y));
}

void Game::update()
{
    _gameObjects.update();
}

void Game::draw()
{
    _display.clear();
    _display.apply(_gameObjects);
    _display.renderPresent();
}
