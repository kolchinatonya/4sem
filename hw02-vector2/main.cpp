#include <iostream>
#include "Vector2.h"

using namespace std;


Vector2 Input(string name)
{
    cout << "Input " << name << ":" << endl;
    Vector2 v;
    cin >> v;
    cout.precision(3);
    cout << "Your vector is: " << v << endl;
    return v;
}

int main()
{
    Vector2 v1 = Input("v1");
    Vector2 v2 = Input("v2");
    cout << "v1 + v2 = " << v1 + v2 << endl;
    v1 += v2;
    cout << "v1 += v2  ->  v1 = " << v1 << endl;
    cout << "v1 - v2 = " << v1 - v2 << endl;
    v1 -= v2;
    cout << "v1 -= v2  ->  v1 = " << v1 << endl;
    cout << "v1 * v2 = " << v1 * v2 << endl;
    cout << "v1 ^ v2 = " << (v1 ^ v2) << endl;
    cout << "2 * v1 = " << 2 * v1 << endl;
    cout << "v1 * 2 = " << v1 * 2 << endl;
    cout << "v1 / 2 = " << v1 / 2 << endl;
    cout << "v1.Perpendicular() = " << v1.Perpendicular() << endl;
    cout << "v1.Norm() = " << v1.Norm() << endl;
    cout << "v1.Len() = " << v1.Len() << endl;
    cout << "v1.SquareLen() = " << v1.SquareLen() << endl;
    cout << "v1.Rotate(Pi/3) = " << v1.Rotate(M_PI / 3) << endl;
    v1.GetRotated(M_PI / 3);
    cout << "v1.GetRotated(Pi/3)  ->  v1 = " << v1 << endl;
    return 0;
}