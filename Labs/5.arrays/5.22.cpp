#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    string in;
    char find;
    vector<string> data;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> in;
        data.push_back(in);
    }
    cin >> find;
    for (int i = 0; i < data.size(); i++)
    {
        if (data.at(i).find(find) != string::npos)
        {
            cout << data.at(i) << ",";
        }
    }
    cout << endl;

    return 0;
}