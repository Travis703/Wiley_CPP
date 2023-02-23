#include <iostream>
#include <string>
using namespace std;

int main()
{
    string firstname, lastname;

    cin >> firstname;
    getline(cin, lastname);

    if (lastname.find(" ", 1) != string::npos)
    {
        cout << lastname.substr(lastname.find(" ", 1) + 1, lastname.length() - lastname.find(" ", 1)) << ", " << firstname.at(0) << "." << lastname.at(1) << "." << endl;
    }
    else
    {
        cout << lastname.substr(1, lastname.length()) << ", " << firstname.at(0) << "." << endl;
    }

    return 0;
}