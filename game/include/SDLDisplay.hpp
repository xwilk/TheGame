#pragma once

#include <map>
#include <memory>

#include "Sdl.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"
#include "GameObjectType.hpp"

struct GameObjects;


class SDLDisplay
{
public:
    SDLDisplay();

    void clear();
    void apply(GameObjects&);
    void renderPresent();

private:
    Sdl _sdl;
    Window _window;
    Renderer _renderer;
    std::map<GameObjectType, std::unique_ptr<Texture>> _textures;
};
