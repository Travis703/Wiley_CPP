#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Write function to create and output all permutations of the list of names.
void PrintAllPermutations(vector<string> &perm, vector<string> &name)
{
    if (name.size() == 0)
    {
        cout << perm.at(0);
        for (int i = 1; i < perm.size(); i++)
        {
            cout << ", " << perm.at(i);
        }
        cout << endl;
    }
    for (int i = 0; i < name.size(); i++)
    {
        perm.push_back(name.at(i));
        name.erase(name.begin() + i);
        PrintAllPermutations(perm, name);
        name.insert(name.begin() + i, perm.at(perm.size() - 1));
        perm.erase(perm.end());
    }
}

int main()
{
    vector<string> name;
    vector<string> perm;
    string in;

    // TODO: Read a list of names into nameList; stop when -1 is read. Then call recursive function.
    cin >> in;
    while (in != "-1")
    {
        name.push_back(in);
        cin >> in;
    }
    PrintAllPermutations(perm, name);

    return 0;
}