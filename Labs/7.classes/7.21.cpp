
#include <iostream>
#include "Triangle.h"
using namespace std;

int main()
{
    Triangle triangle1;
    Triangle triangle2;

    double b1, b2, h1, h2;

    cin >> b1 >> h1 >> b2 >> h2;

    triangle1.SetBase(b1);
    triangle1.SetHeight(h1);
    triangle2.SetBase(b2);
    triangle2.SetHeight(h2);

    cout << "Triangle with smaller area:" << endl;
    (triangle1.GetArea() < triangle2.GetArea()) ? triangle1.PrintInfo() : triangle2.PrintInfo();

    return 0;
}