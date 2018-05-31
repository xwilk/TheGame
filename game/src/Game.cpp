#include <iostream>
#include <SDL.h>

#include "Game.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "Collisions.hpp"
#include "Consts.hpp"


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
    _gameObjects.player.updatePosition();

    for (auto& zombie : _gameObjects.zombies)
    {
        zombie.updatePosition(_gameObjects.player.position());
    }

    for (auto i = 0u; i < _gameObjects.projectiles.size(); ++i)
    {
        auto& projectile = _gameObjects.projectiles[i];
        projectile.updatePosition();

        for (auto j = 0u; j < _gameObjects.zombies.size(); ++j)
        {
            auto& zombie = _gameObjects.zombies[j];

            if (objectsCollide(projectile, zombie))
            {
                _gameObjects.projectiles.erase(_gameObjects.projectiles.begin() + i);
                zombie.takeDamage();

                if (zombie.isDead())
                {
                    _gameObjects.zombies.erase(_gameObjects.zombies.begin() + j);
                    _gameObjects.player.score();
                }

                break;
            }
        }
    }

    _gameObjects.spawnEnemies();
}

void Game::draw()
{
    _display.clear();
    _display.apply(_gameObjects); // I want to pass 'DrawableObjects here'
    _display.renderPresent();
}
