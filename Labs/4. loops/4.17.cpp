#include <iostream>
using namespace std;

int main()
{
    string in;
    getline(cin, in);
    int i = 0;
    while (i < in.length())
    {
        if (!isalpha(in.at(i)))
        {
            in.replace(i, 1, "");
            i--;
        }
        i++;
    }
    cout << in << endl;
    return 0;
}