#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

double StepsToMiles(int step)
{
    if (step < 0)
    {
        throw runtime_error("Exception: Negative step count entered.");
    }
    return step / 2000.0;
}

int main()
{
    int step;
    cin >> step;
    try
    {
        cout << fixed << setprecision(2) << StepsToMiles(step) << endl;
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
    /* Type your code here. */

    return 0;
}
