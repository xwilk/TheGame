#pragma once

#include "StrongType.hpp"


using Width = NamedType<int, struct WidthParam, DividableByFloat>;
using Height = NamedType<int, struct HeightParam, DividableByFloat>;

struct Grid
{
    explicit Grid(Width width, Height height)
        : w(width),
          h(height)
    {}

    int size()
    {
        return w.get() * h.get();
    }

    Width w;
    Height h;
};