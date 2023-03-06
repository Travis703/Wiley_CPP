#include <iostream>

using namespace std;

// TODO: Write recursive PrintNumPattern() function
void PrintNumPattern(int a, int b)
{
    cout << a << " ";
    if (a >= 0)
    {
        PrintNumPattern(a - b, b);
        cout << a << " ";
    }
}

int main()
{
    int num1;
    int num2;

    cin >> num1;
    cin >> num2;

    PrintNumPattern(num1, num2);

    return 0;
}