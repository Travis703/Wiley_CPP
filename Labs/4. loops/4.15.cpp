#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int in, max, count, sum;
    cin >> in;
    max = in;
    count = 0;
    sum = 0;
    while (in >= 0)
    {

        if (in > max)
        {
            max = in;
        }
        count++;
        sum += in;
        cin >> in;
    }


    cout << max << " " << fixed << setprecision(2) << static_cast<double>(sum) / (count) << endl;

    return 0;
}