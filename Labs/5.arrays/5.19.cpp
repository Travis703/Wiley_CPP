#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> data;
    int in;
    do
    {
        cin >> in;
        data.push_back(in);
        if (data.size() > 10)
        {
            cout << "Too many numbers" << endl;
            return 0;
        }
    } while (in >= 0);
    cout << "Middle item: " << data.at((data.size() - 1) / 2) << endl;

    return 0;
}