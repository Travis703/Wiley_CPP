#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int num;
    double in, max = 0;
    vector<double> data;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> in;
        data.push_back(in);
        if (in > max)
        {
            max = in;
        }
    }

    for (int i = 0; i < data.size(); i++)
    {
        cout << fixed << setprecision(2) << data.at(i) / max << " ";
    }

    cout << endl;

    return 0;
}