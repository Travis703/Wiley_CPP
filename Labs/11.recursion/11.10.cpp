#include <iostream>
using namespace std;

int Fibonacci(int n)
{

    if (n < 0)
    {
        return -1;
    }
    else if (n <= 1)
    {
        return n;
    }
    
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    int startNum = 7;

    // cin >> startNum;
    cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;

    return 0;
}
