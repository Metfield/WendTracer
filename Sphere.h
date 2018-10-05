#pragma once
#include "Vector3.h"
#include "Hitable.h"

class Ray;

// r*r = x*x + y*y + z*z
// dot(p - c, p - c) = r*r
// dot(p(t) - c, p(t) - c) = r*r
// dot(o + t*d - c, o + t*d) = r*r
// t*t*dot(d, d) + 2*t*dot(d, o - c) + dot(o - c, o - c) - r*r = 0
// Solve with quadratic where
//    t > 0: two real intersections
//    t = 0: one intersection
class Sphere : public Hitable
{
public:
    Vector3 center;
    float radius;

    Sphere() { }
    Sphere(Vector3& _center, float _radius) : center(_center), radius(_radius) { }

    virtual bool Hit(const Ray& ray, float tMin, float tMax, HitInfo& hitInfo) const override;
};