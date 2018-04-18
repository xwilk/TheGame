#pragma once

#include "Sdl.hpp"
#include "FrameRate.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Dimensions.hpp"

//Temp
#include <vector>
#include "Math.hpp"
#include "Point.hpp"

class Player;
class Zombie;
class Texture;


class Game
{
public:
    Game();

    void run();

    class Projectile
    {
    public:
        Projectile(Point position, float rotation)
            : _position(position),
              _rotation(Math::ToRadians(rotation))
        {
        }

        void updatePosition(float deltaTime = 1.f)
        {
            if (!Math::NearZero(_speed))
            {
                auto forwardVector = Vector2::getForwardVector(_rotation);
                _position += forwardVector * _speed * deltaTime;
            }
        }

        Point position() const
        {
            return _position;
        }

        float rotation() const
        {
            return Math::ToDegrees(_rotation);
        }

    private:
        Point _position;
        float _rotation;
        int _speed = 3;
    };

private:
    void handleInput(Player&);
    void update(Player&, Zombie&);
    void draw(Texture&, Texture&, Texture&, Texture&, Player&, Zombie&);

    Sdl _sdl;
    FrameRate _frame;
    Window _window;
    Renderer _renderer;

    bool _isRunning = true;

    std::vector<Projectile> _projectiles;
};
