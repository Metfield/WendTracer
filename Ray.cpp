#include "Ray.h"

Vector3 Ray::GetPoint(float t) const
{
    return origin + t*direction;
}

Vector3 Ray::GetClearColor()
{
    Vector3 unitDirection = UnitVector(direction);
    float t = 0.5f * unitDirection.y + 1.0f;

    return Lerp(Vector3(1.0f, 1.0f, 1.0f), Vector3(0.5f, 0.7f, 1.0f), t);
}