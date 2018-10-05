#include <iostream>
#include <fstream>
#include <math.h>
#include <float.h>

#include "Vector3.h"
#include "Ray.h"

#include "Sphere.h"

#include "Hitable.h"
#include "HitableList.h"

using namespace std;

#define width 200
#define height 100

Vector3 GetClearColor(Vector3 rayDirection)
{
    Vector3 unitDirection = UnitVector(rayDirection);
    float t = 0.5f * unitDirection.y + 1.0f;

    return Lerp(Vector3(1.0f, 1.0f, 1.0f), Vector3(0.5f, 0.7f, 1.0f), t);
}

Vector3 Color(const Ray& ray, Hitable *world)
{
    HitInfo hitInfo;

    if(world->Hit(ray, 0, MAXFLOAT, hitInfo))
        return 0.5f * Vector3(hitInfo.normal.x + 1, hitInfo.normal.y + 1, hitInfo.normal.z + 1);
    
    return GetClearColor(ray.direction);
}

int main() 
{
    ofstream fileStream;
    fileStream.open("Poop.ppm");
    
    fileStream << "P3\n" << width << " " << height << "\n255\n";

    Vector3 lowerLeft(-width / 100, -height / 100, -1);
    Vector3 horizontal(4, 0, 0);
    Vector3 vertical(0, 2, 0);

    Vector3 origin(0, 0, 0);
    Vector3 sphereCenter(0, 0, -1);

    Hitable *hitables[2];
    hitables[0] = new Sphere(sphereCenter, 0.5);
    
    sphereCenter -= Vector3(0, 100.5, 0);
    hitables[1] = new Sphere(sphereCenter, 100);

    Hitable *world = new HitableList(hitables, 2);

    for(int j = height - 1; j >= 0; j--)
    {
        for(int i = 0; i < width; i++)
        {
            float u = float(i) / float(width);
            float v = float(j) / float(height);

            Ray ray(origin, lowerLeft + u*horizontal + v*vertical);
            Vector3 color = Color(ray, world);

            int ir = (255.99 * color.x);
            int ig = (255.99 * color.y);
            int ib = (255.99 * color.z);

            fileStream << ir << " " << ig << " " << ib << "\n";
        }
    }

    fileStream.close();
    return 1;
}