#pragma once

#include "Circle.hpp"
#include "Rectangle.hpp"


template <typename A, typename B>
bool objectsCollide(const A& a, const B& b)
{
    return intersect(a.collisionArea(), b.collisionArea());
}

bool intersect(const Circle& a, const Circle& b);
bool intersect(const Circle& circle, const Rectangle& rect);
bool intersect(const Rectangle& rect, const Circle& circle);
