#pragma once

#include <iostream>
#include <exception>
#include <math.h>

using namespace std;

class Vector2{

public:
    Vector2();
    Vector2(float x1, float y1);
    float X() const;
    float Y() const;
    Vector2 operator+(const Vector2& other) const;
    Vector2& operator+=(const Vector2& other);
    Vector2 operator-(const Vector2& other) const;
    Vector2& operator-=(const Vector2& other);
    float operator*(const Vector2& other) const;
    float operator^(const Vector2& other) const;
    Vector2 operator*(float k) const;
    Vector2 operator/(float k) const;
    Vector2 Perpendicular() const;
    Vector2 Norm() const;
    float  SquareLen()  const;
    float  Len()  const;
    Vector2 operator-() const;
    Vector2 Rotate(float alfa);
    Vector2& GetRotated(float alfa);

private:
    float x, y;

};

Vector2 operator*(float k, const Vector2& v);
ostream& operator<<(ostream& stream, const Vector2& v);
istream& operator>>(istream& stream, Vector2& v);

