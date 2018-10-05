#include "Sphere.h"
#include "Ray.h"

#include <math.h>

bool Sphere::Hit(const Ray& ray, float tMin, float tMax, HitInfo& hitInfo) const
{
    Vector3 oc = ray.origin - center;

    float a = Dot(ray.direction, ray.direction);
    float b = 2 * Dot(oc, ray.direction);
    float c = Dot(oc, oc) - radius * radius;

    // Chicharronera ftw!
    float discriminant = b*b - 4*a*c;
    if(discriminant < 0)
        return false;

    // TODO: Beautify this shit code
    float t = (-b - sqrt(discriminant)) / a;
    if(t > tMin && t < tMax)
    {
        hitInfo.t = t;
        hitInfo.point = ray.GetPoint(t);
        hitInfo.normal = (hitInfo.point - center) / radius;
        
        return true;
    }

    // t = (-b + sqrt(discriminant)) / a;
    // if(t > tMin && t < tMax)
    // {
    //     hitInfo.t = t;
    //     hitInfo.point = ray.GetPoint(t);
    //     hitInfo.normal = (hitInfo.point - center) / radius;

    //     return true;
    // }

    return false;
}
