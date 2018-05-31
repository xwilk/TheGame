#pragma once

#include <stdexcept>
#include <vector>

#include <SDL.h>

#include "Dimensions.hpp"
#include "Renderer.hpp"
#include "Point.hpp"


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
        SDL_Renderer* renderer,
        Width spriteWidth,
        Height spriteHeight,
        Grid);


    ~Texture();

    void render(
        Renderer&,
        Point position,
        double rotation = 0.0);

    void tile(
        Renderer&,
        Width screenWidth,
        Height screenHeight,
        int tileSize);

    void nextClip();

private:
    unsigned _currentClip = 0;
    std::vector<SDL_Rect> _clips;

    SDL_Texture* _texture = nullptr;
};