#include <iostream>
#include <SDL.h>

#include "Game.hpp"
#include "Player.hpp"
#include "Texture.hpp"
#include "ResourcePath.hpp"
#include "Point.hpp"
#include "Collisions.hpp"

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

void makeWalls(std::vector<Wall>& walls, Width screenWidth)
{
    int x = 16, y = 16;
    while (x < screenWidth.get())
    {
        walls.emplace_back(Point{float(x), float(y)});
        x += 32;
    }
}

void Game::run()
{
    auto player = Player{};
    _zombies.emplace_back(Point{500, 500});
    makeWalls(_walls, SCREEN_WIDTH);

    while (_isRunning)
    {
        _frame.start();

        handleInput(player);
        update(player);
        draw(player);

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
    }

    if (currentKeyStates[SDL_SCANCODE_D])
    {
        player.useSideMove(SIDEMOVE::RIGHT);
    }

    int mouse_x = 0, mouse_y = 0;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    player.rotateTowards(Point(mouse_x, mouse_y));
}

void Game::update(Player& player)
{
    player.updatePosition();

    for (auto& zombie : _zombies)
    {
        zombie.updatePosition(player.position());
    }

    for (auto i = 0u; i < _projectiles.size(); ++i)
    {
        auto& projectile = _projectiles[i];
        projectile.updatePosition();

        for (auto j = 0u; j < _zombies.size(); ++j)
        {
            auto& zombie = _zombies[j];

            if (objectsCollide(projectile, zombie))
            {
                _projectiles.erase(_projectiles.begin() + i);
                zombie.takeDamage();

                if (zombie.isDead())
                {
                    _zombies.erase(_zombies.begin() + j);
                    player.score();
                }

                break;
            }
        }
    }

    spawnEnemies(player.currentScore());
}

void Game::spawnEnemies(unsigned playerScore)
{
    if (playerScore > _zombies.size())
    {
        auto x = playerScore % 2 == 0 ? 100.f : 540.f;
        auto y = _zombies.size() % 2 == 0 ? 100.f : 380.f;
        _zombies.emplace_back(Point{x, y});
    }
}

void Game::draw(Player& player)
{
    SDL_RenderClear(_renderer);
    _renderer.apply(player, _zombies, _walls, _projectiles);
    SDL_RenderPresent(_renderer);
}
