#include <iostream>
using namespace std;

int main()
{
    int input;
    cin >> input;
    if (input < 1)
    {
        cout << "No change" << endl;
        return 0;
    }
    if (input / 100 > 0)
    {
        cout << input / 100 << ((input / 100 == 1) ? " Dollar" : " Dollars") << endl;
        input -= (input / 100) * 100;
    }
    if (input / 25 > 0)
    {

        cout << input / 25 << ((input / 25 == 1) ? " Quarter" : " Quarters") << endl;
        input -= (input / 25) * 25;
    }
    if (input / 10 > 0)
    {

        cout << input / 10 << ((input / 10 == 1) ? " Dime" : " Dimes") << endl;
        input -= (input / 10) * 10;
    }
    if (input / 5 > 0)
    {

        cout << input / 5 << ((input / 5 == 1) ? " Nickel" : " Nickels") << endl;
        input -= (input / 5) * 5;
    }
    if (input > 0)
    {

        cout << input << ((input == 1) ? " Penny" : " Pennis") << endl;
    }
    return 0;
}