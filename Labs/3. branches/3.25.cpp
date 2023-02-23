#include <iostream>
using namespace std;

int main()
{
    int year;
    bool isleap;
     cin>>year;

    if (year % 4 == 0)
    {
        isleap = 1;

        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                isleap = 1;
            }
            else
            {
                isleap = 0;
            }
        }
    }
    else
    {
        isleap = 0;
    }
    cout << year << ((isleap) ? " - leap year" : " - not a leap year") << endl;
    return 0;
}