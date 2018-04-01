#include <iostream>
#include <SDL.h>

#include "Texture.hpp"


inline void logSDLError(std::ostream &os, const std::string &msg)
{
    os << msg << " error: " << SDL_GetError() << std::endl;
}

inline void renderTexture(
    Texture& texture,
    Renderer& renderer,
    SDL_Rect* dst,
    SDL_Rect* clip = nullptr)
{
    SDL_RenderCopy(renderer, texture, clip, dst);
}

inline Texture loadTexture(const std::string& filePath, Renderer& renderer)
{
    return Texture(filePath, renderer);
}

inline void tile(
    Texture& texture,
    Renderer& renderer,
    Width screenWidth,
    Height screenHeight,
    int tileSize)
{
    int x = 0, y = 0;
    while (x < screenWidth)
    {
        while (y < screenHeight)
        {
            SDL_Rect dst = {x, y, tileSize, tileSize};
            renderTexture(texture, renderer, &dst);
            y += tileSize;
        }

        x += tileSize;
        y = 0;
    }
}
