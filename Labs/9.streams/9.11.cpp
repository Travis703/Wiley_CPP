#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
// Include any necessary libraries here.

using namespace std;

int main()
{

    string in, name;
    ifstream file;

    cin >> name;
    file.open(name);
    file >> in;
    while (!file.eof())
    {

        in.replace(in.find("_") + 1, in.length() - in.find("_") - 1, "info.txt");
        cout << in << endl;
        file >> in;
    }
    file.close();

    return 0;
}
