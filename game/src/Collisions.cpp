#include "Collisions.hpp"


bool intersect(const Circle& a, const Circle& b)
{
    auto distanceBetweenCenters = (a.center - b.center).Length();
    auto radiiSum = a.radius + b.radius;

    return distanceBetweenCenters < radiiSum;
}

bool intersect(const Circle& circle, const Rectangle& rect)
{
    return false;
}

bool intersect(const Rectangle& rect, const Circle& circle)
{
    intersect(circle, rect);
}
