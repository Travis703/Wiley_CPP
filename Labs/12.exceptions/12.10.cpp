#include <iostream>
using namespace std;

int main()
{
    cin.exceptions(ios::failbit); // Allow cin to throw exceptions
    int val1;
    int val2;
    int val3;
    int max;

    val1 = 0;
    val2 = 0;
    val3 = 0;
    try
    {
        cin >> val1 >> val2 >> val3;

        if (val1 > val2)
        {
            cout << ((val1 > val3) ? val1 : val3) << endl;
        }
        else if (val2 > val3)
        {
            cout << val2 << endl;
        }
        else
        {
            cout << val3 << endl;
        }
    }
    catch (ios_base::failure &e)
    {
        if (val1 == 0)
        {
            cout << "0 input(s) read:" << endl;
            cout << "No max" << endl;
        }
        else if (val2 == 0)
        {
            cout << "1 input(s) read:" << endl;
            cout << "Max is " << val1 << endl;
        }
        else
        {
            cout << "2 input(s) read:" << endl;
            cout << "Max is " << ((val1 > val2) ? val1 : val2) << endl;
        }
    }

    /* Type your code here. */

    return 0;
}
