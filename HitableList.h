#pragma once
#include "Hitable.h"

class HitableList : public Hitable
{
public:
    Hitable **list;
    int size;

public:
    HitableList();
    HitableList(Hitable **_list, int n) : list(_list), size(n) { }

    virtual bool Hit(const Ray& ray, float tMin, float tMax, HitInfo& hitInfo) const override;
};