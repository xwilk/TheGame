#pragma once

#include <vector>
#include "FrameRate.hpp"
#include "SDLDisplay.hpp"
#include "GameObjects.hpp"


class Game
{
public:
    Game();

    void run();

private:
    void handleInput();
    void update();
    void draw();

    FrameRate _frame;
    SDLDisplay _display;
    GameObjects _gameObjects;

    bool _isRunning = true;
};
