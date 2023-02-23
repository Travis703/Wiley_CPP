#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, thresh, in;
    vector<int> data;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> in;
        data.push_back(in);
    }
    cin >> thresh;
    for (int i = 0; i < data.size(); i++)
    {
        if (data.at(i) < thresh)
        {
            cout << data.at(i) << ",";
        }
    }

    cout << endl;
    return 0;
}