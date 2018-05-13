#pragma once

#include "Point.hpp"
#include "Dimensions.hpp"


struct Rectangle
{
    explicit Rectangle(Point center, Width width, Height height)
        : topLeft(Point{center.x - (width.get() / 2), center.y - (height.get() / 2)}),
          w(width),
          h(height)
    {
    }

    Point topLeft;
    Width w;
    Height h;
};