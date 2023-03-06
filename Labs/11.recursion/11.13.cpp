#include <iostream>
using namespace std;

/* TODO: Write recursive DigitCount() function here. */
int DigitCount(int a)
{
    if (a < 10)
    {
        return 1;
    }
    return 1 + DigitCount(a / 10);
}

int main()
{
    int num;
    int digits;

    cin >> num;
    digits = DigitCount(num);
    cout << digits << endl;
    return 0;
}
