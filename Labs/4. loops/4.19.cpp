#include <iostream>
#include <string>
using namespace std;

int main()
{
    string in;
    getline(cin, in);
    while (tolower(in.at(0)) != 'd')
    {

        for (int i = in.length() - 1; i >= 0; i--)
        {
            cout << in.at(i);
        }
        cout << endl;
        getline(cin, in);
    }
    return 0;
}