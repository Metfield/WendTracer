#include <iostream>
#include <fstream>
#include <math.h>

#include "Vector3.h"
#include "Ray.h"

#include "Sphere.h"

using namespace std;

#define width 200
#define height 100

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

    Sphere sphere(sphereCenter, 0.5);

    for(int j = height - 1; j >= 0; j--)
    {
        for(int i = 0; i < width; i++)
        {
            float u = float(i) / float(width);
            float v = float(j) / float(height);

            Ray ray(origin, lowerLeft + u*horizontal + v*vertical);

            Vector3 color;
            float t = sphere.RayHit(ray);
            if(t > 0)
            {
                Vector3 normal = UnitVector(ray.GetPoint(t) + Vector3(0, 0, -1));
                color = 0.5 * Vector3(normal.x + 1, normal.y + 1, normal.z + 1 );
            }
            else
            {
                color = ray.GetClearColor();
            }
                

            int ir = (255.99 * color.x);
            int ig = (255.99 * color.y);
            int ib = (255.99 * color.z);

            fileStream << ir << " " << ig << " " << ib << "\n";
        }
    }

    fileStream.close();
    return 1;
}