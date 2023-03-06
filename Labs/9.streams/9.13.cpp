#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file;
    string name, in;
    cin >> name;
    file.open(name);
    getline(file, in);
    while (!file.eof())
    {

        if (in.find("\t", in.length() - 10) != string::npos)
        {
            int base = in.find("\t");
            cout << in.substr(base + 1, in.find("\t", base + 1) - base - 1) + " (" + in.substr(0, base) + ") -- " + in.substr(in.find("\t", base + 1) + 1, in.find("\t", in.length() - 10) - in.find("\t", base + 1) - 1) << endl;
        }

        getline(file, in);
    }

    return 0;
}