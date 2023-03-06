#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;
    string name, in;
    char letter;
    cin >> name >> letter;
    file.open(name + ".txt");
    getline(file, in);
    while (!file.eof())
    {
        // cout << in << endl;
        if (in[0] == letter)
        {
            int i = in.find(" ");
            cout << in.substr(0, in.find(" ")) << endl;
            while (in.find(" ", i) != string::npos)
            {
                cout << in.substr(i + 1, in.find(" ", i + 1) - i - 1) << endl;
                i = in.find(" ", i + 1);
            }
            return 1;
        }
        getline(file, in);
    }
    cout << "No synonyms for " << name << " begin with " << letter << "." << endl;
    return 0;
}
