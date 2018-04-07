#pragma once

#include <SDL.h>


class Point
{
public:
    explicit Point(float x, float y) : x(x), y(y) {}

    float x;
    float y;
};