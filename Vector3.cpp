#include "Vector3.h"
#include <iostream>
#include <math.h>

using namespace std;

inline float Vector3::Length() const
{
    return x*x + y*y + z*z;
}

inline float Vector3::SquaredLength() const
{
    return sqrtf(this->Length());
}

inline void Vector3::MakeUnitVector()
{
    float k = 1.0f / SquaredLength();
    x *= k;
    y *= k;
    z *= k;
}

Vector3 Vector3::UnitVector(Vector3 vector)
{
    return vector / vector.Length();
}

inline float Vector3::Dot(const Vector3 &other)
{
    return Vector3::Dot(*this, other);
}

inline Vector3 Vector3::Cross(const Vector3 &other)
{
    return Vector3::Cross(*this, other);
}
    
inline float Vector3::Dot(const Vector3 &v1, const Vector3 &v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

inline Vector3 Vector3::Cross(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3( v1.y*v2.z - v1.z*v2.y,
                  -(v1.x*v2.z - v1.z*v2.x),
                    v1.x*v2.y - v1.y*v2.x);
}

Vector3 Vector3::Lerp(const Vector3 &from, const Vector3 &to, float t)
{
    return (1.0f - t) * from + t * to;
}

inline Vector3 Vector3::operator-(const Vector3& other)
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

inline Vector3 Vector3::operator*(const Vector3 &other)
{
    return Vector3(x*other.x, y*other.y, z*other.z);
}

inline Vector3 Vector3::operator*(const float &scalar)
{
    return Vector3(x*scalar, y*scalar, z*scalar);
}

inline Vector3 Vector3::operator/(const Vector3 &other)
{
    return Vector3(x/other.x, y/other.y, z/other.z);
}

inline Vector3 Vector3::operator/(const float &scalar)
{
    return Vector3(x/scalar, y/scalar, z/scalar);
}

inline Vector3& Vector3::operator+=(const Vector3 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

inline Vector3& Vector3::operator-=(const Vector3 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

inline Vector3& Vector3::operator*=(const Vector3 &other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;

    return *this;
}

inline Vector3& Vector3::operator/=(const Vector3 &other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;

    return *this;
}

inline Vector3& Vector3::operator*=(const float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

inline Vector3& Vector3::operator/=(const float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

inline std::istream& Vector3::operator>>(std::istream &is)
{
    is >> x >> y >> z;
    return is;
}

inline std::ostream& Vector3::operator<<(std::ostream &os)
{
    os << x << " " << y << " " << z;
    return os;
}