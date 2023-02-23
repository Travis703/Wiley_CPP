#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> data;
    int len, in;
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> in;
        data.push_back(in);
    }

    for (int i = data.size() - 1; i >= 0; i--)
    {
        cout << data.at(i) << ",";
    }
    cout << endl;

    return 0;
}