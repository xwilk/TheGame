#include "Collisions.hpp"


bool intersect(const Circle& a, const Circle& b)
{
    auto distanceBetweenCenters = (a.center - b.center).Length();
    auto radiiSum = a.radius + b.radius;

    return distanceBetweenCenters < radiiSum;
}

bool intersect(const Circle& circle, const Rectangle& rect)
{
    return circle.center.x + circle.radius > rect.topLeft.x
        && circle.center.x - circle.radius < rect.topLeft.x + rect.w.get()
        && circle.center.y + circle.radius > rect.topLeft.y
        && circle.center.y - circle.radius < rect.topLeft.y + rect.h.get();
}

bool intersect(const Rectangle& rect, const Circle& circle)
{
    return intersect(circle, rect);
}
