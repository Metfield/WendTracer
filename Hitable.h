#pragma once
#include "Ray.h"

typedef struct HitInfo
{
    float t;
    Vector3 point;
    Vector3 normal;
} HitInfo;

class Hitable
{
public:
    virtual bool Hit(const Ray& ray, float tMin, float tMax, HitInfo& hitInfo) const = 0;
};