#pragma once

#include <stdexcept>
#include <SDL.h>

#include "Window.hpp"

class RendererError : public std::runtime_error
{
public:
    RendererError(const std::string& what_arg)
        : std::runtime_error(what_arg)
    {}
};


class Renderer
{
public:
    Renderer(Window& window)
    {
        _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (not _renderer)
            throw RendererError("CreateRenderer");
    }

    ~Renderer()
    {
        SDL_DestroyRenderer(_renderer);
    }

    operator SDL_Renderer*()
    {
        return _renderer;
    }

private:
    SDL_Renderer* _renderer;
};
