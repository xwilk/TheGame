#pragma once

#include <stdexcept>

#include <SDL.h>
#include <SDL_image.h>

#include "Surface.hpp"
#include "Renderer.hpp"


class TextureLoadingError : public std::runtime_error
{
public:
    TextureLoadingError(const std::string& what_arg)
        : std::runtime_error(what_arg)
    {}
};


class Texture
{
public:
    explicit Texture(
        const std::string& filePath,
        Renderer& renderer)
    {
        _texture = IMG_LoadTexture(renderer, filePath.c_str());

        if (_texture == nullptr)
            throw TextureLoadingError("CreateTextureFromSurface");
    }

    ~Texture()
    {
        SDL_DestroyTexture(_texture);
    }

    operator bool()
    {
        return _texture != nullptr;
    }

    operator SDL_Texture*()
    {
        return _texture;
    }

private:
    SDL_Texture* _texture = nullptr;
};