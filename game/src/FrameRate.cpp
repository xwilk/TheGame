#include <SDL.h>

#include "FrameRate.hpp"


void FrameRate::start()
{
    _frameStart = SDL_GetTicks();
}

void FrameRate::delay()
{
    _frameTime = SDL_GetTicks() - _frameStart;
    if (FRAME_DELAY > _frameTime)
    {
        SDL_Delay(FRAME_DELAY - _frameTime);
    }
}
