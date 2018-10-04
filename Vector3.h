#pragma once
#include <stdlib.h>
#include <iostream>

class Vector3
{
public:
    float x, y, z;
    
public:
    Vector3() { }
    Vector3(float _x, float _y, float _z ) : x(_x), y(_y), z(_z) { }
    
     float Length() const
    {
        return x*x + y*y + z*z;
    }
    
     float SquaredLength() const;
     void MakeUnitVector();

    // const Vector3 operator+() const { return *this; }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }

    Vector3 operator-(const Vector3 &other);
    Vector3 operator*(const Vector3 &other);
    Vector3 operator*(const float &scalar);
    Vector3 operator/(const Vector3 &other);
    Vector3 operator/(const float &scalar);

     Vector3& operator+=(const Vector3 &other);
     Vector3& operator-=(const Vector3 &other);
     Vector3& operator*=(const Vector3 &other);
     Vector3& operator/=(const Vector3 &other);
     Vector3& operator*=(const float scalar);
     Vector3& operator/=(const float scalar);

     std::istream& operator>>(std::istream &is);
     std::ostream& operator<<(std::ostream &os);
};

inline Vector3 operator+(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline  Vector3 operator-(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline  Vector3 operator*(const float scalar, const Vector3 &v)
{
    return Vector3(v.x*scalar, v.y*scalar, v.z*scalar);
}

inline  Vector3 operator/(const Vector3 &v, const float scalar)
{
    return Vector3(v.x/scalar, v.y/scalar, v.z/scalar);
}

// Non-member functions
Vector3 UnitVector(Vector3 vector);
float Dot(const Vector3 &v1, const Vector3 &v2);
Vector3 Cross(const Vector3 &v1, const Vector3 &v2);
Vector3 Lerp(const Vector3 &from, const Vector3 &to, float t);