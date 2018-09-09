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
    
    inline float Length() const;
    inline float SquaredLength() const;
    inline void MakeUnitVector();

    inline float Dot(const Vector3 &other);
    inline Vector3 Cross(const Vector3 &other);
    
    // Static functions
    static Vector3 UnitVector(Vector3 vector);
    static float Dot(const Vector3 &v1, const Vector3 &v2);
    static Vector3 Cross(const Vector3 &v1, const Vector3 &v2);

    static Vector3 Lerp(const Vector3 &from, const Vector3 &to, float t);

    //inline const Vector3 operator+() const { return *this; }
    inline Vector3 operator-() const { return Vector3(-x, -y, -z); }

    inline Vector3 operator-(const Vector3 &other);
    inline Vector3 operator*(const Vector3 &other);
    inline Vector3 operator*(const float &scalar);
    inline Vector3 operator/(const Vector3 &other);
    inline Vector3 operator/(const float &scalar);

    inline Vector3& operator+=(const Vector3 &other);
    inline Vector3& operator-=(const Vector3 &other);
    inline Vector3& operator*=(const Vector3 &other);
    inline Vector3& operator/=(const Vector3 &other);
    inline Vector3& operator*=(const float scalar);
    inline Vector3& operator/=(const float scalar);

    inline std::istream& operator>>(std::istream &is);
    inline std::ostream& operator<<(std::ostream &os);
};

// Non-member functions
inline Vector3 operator+(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline Vector3 operator-(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline Vector3 operator*(const float scalar, const Vector3 &v)
{
    return Vector3(v.x*scalar, v.y*scalar, v.z*scalar);
}

inline Vector3 operator/(const float scalar, const Vector3 &v)
{
    return Vector3(v.x/scalar, v.y/scalar, v.z/scalar);
}