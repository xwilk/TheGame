#include <stdexcept>

#include <SDL.h>
#include <SDL_image.h>


class SdlError : public std::runtime_error
{
public:
    SdlError(const std::string& what_arg) 
        : runtime_error(what_arg)
    {} 
};


class Sdl
{
public:
    Sdl()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            throw SdlError("SDLInit");

        if (not IMG_Init(IMG_INIT_PNG))
            throw SdlError("ImageInit");
    }

    ~Sdl()
    {
        IMG_Quit();
        SDL_Quit();
    }
};