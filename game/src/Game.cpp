#include <iostream>
#include <SDL.h>

#include "Game.hpp"


Game::Game()
    : _display(),
      _inputPort(),
      _gameObjects(_inputPort)
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
                _gameObjects.player.position,
                _gameObjects.player.rotation());
        }
    }

    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if (currentKeyStates[SDL_SCANCODE_W])
    {
        _inputPort.push(Message{InputMsgId::INCREASE_SPEED});
    }

    if (currentKeyStates[SDL_SCANCODE_S])
    {
        _inputPort.push(Message{InputMsgId::DECREASE_SPEED});
    }

    if (currentKeyStates[SDL_SCANCODE_A])
    {
        _inputPort.push(Message{InputMsgId::SIDEMOVE_LEFT});
    }

    if (currentKeyStates[SDL_SCANCODE_D])
    {
        _inputPort.push(Message{InputMsgId::SIDEMOVE_RIGHT});
    }

    int mouse_x = 0, mouse_y = 0;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    _inputPort.push(Message{InputMsgId::ROTATE, Rotate{Point(mouse_x, mouse_y)}});
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
