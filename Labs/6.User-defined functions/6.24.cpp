#include <iostream>
#include <vector>
using namespace std;

void SortVector(vector<int> &data)
{
    for (int i = 0; i < data.size() - 1; i++)
    {
        for (int k = i + 1; k < data.size(); k++)
        {

            if (data.at(i) < data.at(k))
            {
                int temp = data.at(i);
                data.at(i) = data.at(k);
                data.at(k) = temp;
            }
        }
    }
}

int main()
{
    int size, in;
    vector<int> data;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> in;
        data.push_back(in);
    }
    SortVector(data);
    for (int i = 0; i < data.size(); i++)
    {
        cout << data.at(i) << ",";
    }

    return 0;
}