#pragma once

#include <vector>
#include "FrameRate.hpp"
#include "SDLDisplay.hpp"
#include "GameObjects.hpp"
#include "InputPort.hpp"


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
    InputPort _inputPort;
    GameObjects _gameObjects;

    bool _isRunning = true;
};
