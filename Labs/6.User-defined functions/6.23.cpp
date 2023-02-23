#include <iostream>
#include <cstdlib>
using namespace std;

string CoinFlip()
{

    if (rand() % 2)
    {
        return "Heads";
    }
    return "Tails";
}

int main()
{
    srand(2);
    int in;
    cin >> in;
    for (int i = 0; i < in; i++)
    {
        cout << CoinFlip() << endl;
    }
    return 0;
}