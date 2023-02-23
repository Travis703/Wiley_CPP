#include <iostream>
using namespace std;

int Fibonacci(int n)
{
    int a = 0, b = 1, count = 1;
    if (n < 0)
    {
        return -1;
    }
    while (count < n)
    {
        a += b;
        b += a;
        count += 2;
    }
    if (count == n)
    {
        return b;
    }
    return a;
}

int main()
{
    int startNum;

    cin >> startNum;
    cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;

    return 0;
}