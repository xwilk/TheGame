#pragma once

#include "Sdl.hpp"
#include "FrameRate.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Dimensions.hpp"


class Game
{
public:
    Game();

    void run();

private:
    Sdl _sdl;
    FrameRate _frame;
    Window _window;
    Renderer _renderer;
};
