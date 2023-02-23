#include <iostream>
#include <string>
using namespace std;

int main()
{
    string login, first, last;
    int num;
    cin >> first >> last >> num;
    login = last.substr(0, 5) + first.substr(0, 1) + to_string(num % 100);
    cout << "Your login name: " << login << endl;
    return 0;
}