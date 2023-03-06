#include <queue>
#include <iostream>

using namespace std;

int main()
{
    string personName = "";
    int counter = 0;
    int youPosition;

    queue<string> peopleInQueue;

    getline(cin, personName);
    while (personName != "-1")
    {
        // TODO: Add personName to peopleInQueue
        //       determine position of "You" (youPosition)
        peopleInQueue.push(personName);
        if (personName == "You")
        {
            youPosition = peopleInQueue.size();
        }
        getline(cin, personName);
    }

    cout << "Welcome to the ticketing service... " << endl;
    cout << "You are number " << youPosition << " in the queue." << endl;

    int n=peopleInQueue.size();
    for (int i = 0; i < n; i++)
    {
        if (youPosition == 1)
        {
            cout << "You can now purchase your ticket!" << endl;
            return 0;
        }
        cout << peopleInQueue.front() << " has purchased a ticket." << endl;
        peopleInQueue.pop();
        youPosition--;
        cout << "You are now number " << youPosition << endl;
        
    }

    return 0;
}