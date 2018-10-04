#include "Sphere.h"
#include "Ray.h"

#include <math.h>

float Sphere::RayHit(const Ray& ray)
{
    Vector3 oc = ray.origin - center;

    float a = Dot(ray.direction, ray.direction);
    float b = 2 * Dot(oc, ray.direction);
    float c = Dot(oc, oc) - radius * radius;

    // Chicharronera ftw!
    float discriminant = b*b - 4*a*c;
    if(discriminant < 0)
        return -1;

    return (-b - sqrt(discriminant)) / (2*a);
}
