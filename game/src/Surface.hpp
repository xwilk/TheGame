#pragma once

#include <stdexcept>

#include <SDL.h>


class LoadingSurfaceError : public std::runtime_error
{
public:
    LoadingSurfaceError(const std::string& what_arg)
        : std::runtime_error(what_arg)
    {}
};

class Surface
{
public:
    Surface(const std::string& filePath)
    {
        _surface = SDL_LoadBMP(filePath.c_str());

        if (not _surface)
            throw LoadingSurfaceError{"LoadBMP"};
    }

    ~Surface()
    {
        SDL_FreeSurface(_surface);
    }

    operator SDL_Surface*()
    {
        return _surface;
    }

private:
    SDL_Surface* _surface;
};