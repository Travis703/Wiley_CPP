#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

string FindID(string name, ifstream &infoFS)
{
    string names, id;
    while (!infoFS.eof())
    {
        infoFS >> names >> id;
        if (names == name)
        {
            return id;
        }
    }
    throw runtime_error("Student ID not found for " + name);
}

string FindName(string ID, ifstream &infoFS)
{

    string name, id;
    while (!infoFS.eof())
    {
        infoFS >> name >> id;
        if (ID == id)
        {
            return name;
        }
    }
    throw runtime_error("Student name not found for " + ID);
}

int main()
{
    int userChoice;
    string studentName;
    string studentID;

    string studentInfoFileName;
    ifstream studentInfoFS;

    // Read the text file name from user
    cin >> studentInfoFileName;

    // Open the text file
    studentInfoFS.open(studentInfoFileName);

    // Read search option from user. 0: FindID(), 1: FindName()
    cin >> userChoice;

    try
    {
        if (userChoice == 0)
        {
            cin >> studentName;
            studentID = FindID(studentName, studentInfoFS);
            cout << studentID << endl;
        }
        else
        {
            cin >> studentID;
            studentName = FindName(studentID, studentInfoFS);
            cout << studentName << endl;
        }
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
    studentInfoFS.close();
    return 0;
}
