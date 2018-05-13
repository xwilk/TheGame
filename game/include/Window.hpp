#pragma once

#include <stdexcept>
#include <SDL.h>

#include "Dimensions.hpp"


class WindowError : public std::runtime_error
{
public:
    WindowError(const std::string& what_arg)
        : std::runtime_error(what_arg)
    {}
};

class Window
{
public:
    Window(Width w, Height h)
    {
        _window = SDL_CreateWindow("안녕 세상!", 100, 100, w.get(), h.get(), SDL_WINDOW_SHOWN);

        if (not _window)
            throw WindowError("CreateWindow");
    }

    ~Window()
    {
        SDL_DestroyWindow(_window);
    }

    operator SDL_Window*()
    {
        return _window;
    }

private:
    SDL_Window* _window;
};
