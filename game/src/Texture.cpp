#include <SDL_image.h>

#include "Texture.hpp"


Texture::Texture(
    const std::string& filePath,
    SDL_Renderer* renderer,
    Width spriteWidth,
    Height spriteHeight,
    Grid grid)
{
    _texture = IMG_LoadTexture(renderer, filePath.c_str());

    if (_texture == nullptr)
        throw TextureLoadingError("CreateTextureFromSurface");

    for (int i = 0; i < grid.size(); ++i)
    {
        _clips.emplace_back(SDL_Rect{
            i % grid.w.get() * spriteWidth.get(),
            i / grid.h.get() * spriteHeight.get(),
            spriteWidth.get(),
            spriteHeight.get()
        });
    }
}

Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}

namespace
{

void renderTexture(
    SDL_Texture* texture,
    Renderer& renderer,
    SDL_Rect* dst,
    SDL_Rect* clip = nullptr,
    double rotation = 0.0)
{
    SDL_RenderCopyEx(renderer, texture, clip, dst, rotation, nullptr, SDL_FLIP_NONE);
}

}

void Texture::render(
    Renderer& renderer,
    Point position,
    double rotation)
{
    SDL_Rect dst;
    SDL_QueryTexture(_texture, NULL, NULL, &dst.w, &dst.h);

    dst.x = position.x - (dst.w / 2);
    dst.y = position.y - (dst.h / 2);

    renderTexture(_texture, renderer, &dst, &_clips[_currentClip], rotation);
}

void Texture::tile(
    Renderer& renderer,
    Width screenWidth,
    Height screenHeight,
    int tileSize)
{
    int x = 0, y = 0;
    while (x < screenWidth.get())
    {
        while (y < screenHeight.get())
        {
            SDL_Rect dst = {x, y, tileSize, tileSize};
            renderTexture(_texture, renderer, &dst);
            y += tileSize;
        }

        x += tileSize;
        y = 0;
    }
}

void Texture::nextClip()
{
    if (_currentClip < _clips.size() - 1)
    {
        ++_currentClip;
    }
    else
    {
        _currentClip = 0;
    }
}
