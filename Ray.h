#pragma once
#include "Vector3.h"

// P(t) = o + t*d
class Ray 
{
public:
    Vector3 origin;
    Vector3 direction;

public:
    Ray() { }
    Ray(const Vector3& o, const Vector3& d) : origin(o), direction(d) { }

    Vector3 GetPoint(float t) const;
    Vector3 GetClearColor();
};