#include "Vector2.h"



Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Vector2::Vector2(float x1, float y1)
{
    x = x1;
    y = y1;
}

float Vector2::X() const
{
    return x;
}
float Vector2::Y() const
{
    return y;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(x + other.x, y + other.y);
}
Vector2& Vector2::operator+=(const Vector2& other)
{
    x += other.x;
    y += other.y;
    return *this;
}
Vector2 Vector2::operator-(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

Vector2& Vector2::operator-=(const Vector2& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

float Vector2::operator*(const Vector2& other) const
{
    return x * other.x + y * other.y;
}
float Vector2::operator^(const Vector2& other) const
{
    return x * other.y - y * other.x;
}

Vector2 Vector2::operator*(float k) const
{
    return Vector2( x * k, y * k);
}

Vector2 operator*(float k, const Vector2& v)
{
    return  Vector2(v.X() * k, v.Y() * k);
}

Vector2 Vector2::operator/(float k) const
{
    if (k == 0)
        throw exception();
    return Vector2( x / k, y / k);
}

Vector2 Vector2::Perpendicular() const
{
    return Vector2(y, -x);
}

Vector2 Vector2::Norm() const
{
    return Vector2(x / Len(), y / Len());
}

float  Vector2::SquareLen()  const
{
    return x * x + y * y;
}

float  Vector2::Len()  const
{
    return sqrt(SquareLen());
}

Vector2 Vector2::operator-() const
{
    return Vector2(-x, -y);
}

Vector2 Vector2::Rotate(float alfa)
{
    return Vector2(x * cos(alfa) - y * sin(alfa), x * sin(alfa) + y * cos(alfa));
}

Vector2& Vector2::GetRotated(float alfa)
{
    float temp_x = x;
    x = x * cos(alfa) - y * sin(alfa);
    y = temp_x * sin(alfa) + y * cos(alfa);
    return *this;
}

ostream& operator<<(ostream& stream, const Vector2& v)
{
    stream << v.X() << " " << v.Y();
    return stream;
}

istream& operator>>(istream& stream, Vector2& v)
{
    float x, y;
    stream >> x >> y;
    v = Vector2(x, y);
    return stream;
}


