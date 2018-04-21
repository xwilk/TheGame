#pragma once

#include "Circle.hpp"


template <typename A, typename B>
bool objectsCollide(const A& a, const B& b)
{
    return collide(a.collisionArea(), b.collisionArea());
}

inline bool collide(Circle a, Circle b)
{
    auto distanceBetweenCenters = (a.center - b.center).Length();
    auto radiiSum = a.radius + b.radius;

    return distanceBetweenCenters < radiiSum;
}
