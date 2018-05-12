#pragma once

#include "Point.hpp"
#include "Dimensions.hpp"


struct Rectangle
{
    explicit Rectangle(Point center, Width width, Height height)
        : topLeft(Point{center.x - (width / 2), center.y - (height / 2)}),
          w(width),
          h(height)
    {
    }

    Point topLeft;
    Width w;
    Height h;
};