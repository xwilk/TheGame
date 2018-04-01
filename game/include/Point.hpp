#include <SDL.h>


class Point
{
public:
    Point(int x, int y) {}

    operator SDL_Point()
    {
        return SDL_Point{_x, _y};
    }

private:
    int _x;
    int _y;
};