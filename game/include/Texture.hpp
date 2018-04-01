#pragma once

#include <stdexcept>

#include <SDL.h>
#include <SDL_image.h>

#include "Dimensions.hpp"
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
    explicit Texture(const std::string& filePath, Renderer&);
    ~Texture();

    void render(
        Renderer&,
        int x,
        int y,
        SDL_Rect* clip = nullptr,
        double rotation = 0.0);

    void tile(
        Renderer&,
        Width screenWidth,
        Height screenHeight,
        int tileSize);

    operator SDL_Texture*()
    {
        return _texture;
    }

private:
    SDL_Texture* _texture = nullptr;
};