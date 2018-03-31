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

inline void renderTexture(
    Texture& texture, 
    Renderer& renderer, 
    int x, 
    int y,
    SDL_Rect* clip = nullptr)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    renderTexture(texture, renderer, &dst, clip);
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
    int x, y = 0;
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

inline void renderInCenter(
    Texture& texture, 
    Renderer& renderer, 
    Width screenWidth, 
    Height screenHeight)
{
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    int x = (screenWidth / 2) - (w / 2);
    int y = (screenHeight / 2) - (h / 2);

    renderTexture(texture, renderer, x, y);
}
