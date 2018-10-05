#include "HitableList.h"

bool HitableList::Hit(const Ray &ray, float tMin, float tMax, HitInfo& hitInfo) const
{
    HitInfo currentHitInfo;
    bool somethingWasHit = false;
    double closest = tMax;

    for(int i = 0; i < size; i++)
    {
        if(list[i]->Hit(ray, tMin, closest, currentHitInfo))
        {
            somethingWasHit = true;
            closest = currentHitInfo.t;
            hitInfo = currentHitInfo;
        }
    }

    return somethingWasHit;
}