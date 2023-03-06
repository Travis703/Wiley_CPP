#include <iostream>
#include <iomanip>
using namespace std;

/* TODO: Write recursive DrawTriangle() function here. */
void DrawTriangle(int a)
{
    if (a < 0)
    {
        return;
    }
    DrawTriangle(a - 2);

    string s(a, '*');

    cout << setw(10 + (a / 2)) << setfill(' ') << s << endl;
}

int main()
{
    int baseLength;

    cin >> baseLength;
    DrawTriangle(baseLength);
    return 0;
}