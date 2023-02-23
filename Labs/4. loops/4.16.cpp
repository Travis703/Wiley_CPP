#include <iostream>

using namespace std;

int main()
{
    char chara;
    int count = 0;
    string in;
    cin >> chara;
    getline(cin, in);
    for (int i = 0; i < in.length(); i++)
    {
        if (in.at(i) == chara)
        {
            count++;
        }
    }
    cout << count << " " << chara << ((count % 2 == 0) ? "'s" : "") << endl;
    return 0;
}