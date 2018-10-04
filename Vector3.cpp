#include "Vector3.h"
#include <iostream>
#include <math.h>

using namespace std;

float Vector3::SquaredLength() const
{
    return sqrtf(this->Length());
}

void Vector3::MakeUnitVector()
{
    float k = 1.0f / SquaredLength();
    x *= k;
    y *= k;
    z *= k;
}

Vector3 Vector3::operator-(const Vector3& other)
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

 Vector3 Vector3::operator*(const Vector3 &other)
{
    return Vector3(x*other.x, y*other.y, z*other.z);
}

Vector3 Vector3::operator*(const float &scalar)
{
    return Vector3(x*scalar, y*scalar, z*scalar);
}

Vector3 Vector3::operator/(const Vector3 &other)
{
    return Vector3(x/other.x, y/other.y, z/other.z);
}

Vector3 Vector3::operator/(const float &scalar)
{
    return Vector3(x/scalar, y/scalar, z/scalar);
}

Vector3& Vector3::operator+=(const Vector3 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

Vector3& Vector3::operator*=(const Vector3 &other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;

    return *this;
}

Vector3& Vector3::operator/=(const Vector3 &other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;

    return *this;
}

Vector3& Vector3::operator*=(const float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Vector3& Vector3::operator/=(const float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

std::istream& Vector3::operator>>(std::istream &is)
{
    is >> x >> y >> z;
    return is;
}

std::ostream& Vector3::operator<<(std::ostream &os)
{
    os << x << " " << y << " " << z;
    return os;
}

Vector3 UnitVector(Vector3 vector)
{
    return vector / vector.Length();
}

float Dot(const Vector3 &v1, const Vector3 &v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vector3 Cross(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3( v1.y*v2.z - v1.z*v2.y  ,
                 -( v1.x*v2.z - v1.z*v2.x ),
                    v1.x*v2.y - v1.y*v2.x );
}

 Vector3 Lerp(const Vector3 &from, const Vector3 &to, float t)
{
    return (1.0f - t) * from + t * to;
}