#include "Texture.hpp"


Texture::Texture(
    const std::string& filePath,
    Renderer& renderer)
{
    _texture = IMG_LoadTexture(renderer, filePath.c_str());

    if (_texture == nullptr)
        throw TextureLoadingError("CreateTextureFromSurface");
}

Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}

void Texture::render(
    Renderer& renderer,
    int x,
    int y,
    SDL_Rect* clip,
    double rotation)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;

    SDL_QueryTexture(_texture, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopyEx(
        renderer, _texture, clip, &dst, rotation, nullptr, SDL_FLIP_NONE);
}
