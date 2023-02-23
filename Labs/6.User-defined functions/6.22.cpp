#include <iostream>
using namespace std;

void SwapValues(int &num1, int &num2, int &num3, int &num4)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;

    temp = num3;
    num3 = num4;
    num4 = temp;
    cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;
}

int main()
{
    int num1, num2, num3, num4;
    cin >> num1 >> num2 >> num3 >> num4;
    SwapValues(num1, num2, num3, num4);

    return 0;
}