#pragma once

#include "Sdl.hpp"
#include "FrameRate.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Dimensions.hpp"

class Player;


class Game
{
public:
    Game();

    void run();

private:
    void handleInput(Player&);

    Sdl _sdl;
    FrameRate _frame;
    Window _window;
    Renderer _renderer;

    bool _isRunning = true;
};
