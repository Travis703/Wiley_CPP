#include <iostream>
using namespace std;

int main()
{
    int bottles = 21;
    int user_pick, comp_pick;
    string option;
    cout << "There are 21 beer bottles...\nThere are 2 players - Computer and you." << endl;
    cout << "At a time, each one can pick up any no. of bottles between 1 and 4 (inclusive)\nWill you like to play first?" << endl;
    cin >> option;
    option.at(0) = tolower(option.at(0));
    if (option == "yes")
    {
        while (bottles != 1)
        {
            cout << "How many you would like to pick up?" << endl;
            cin >> user_pick;
            while (user_pick > 4 || user_pick < 1)
            {
                cout << "Please pick bottles between 1 and 4 (inclusive)" << endl;
                cin.clear();
                cin.ignore();
                cin >> user_pick;
            }
            comp_pick = 5 - user_pick;
            bottles -= user_pick + comp_pick;
            cout << "Computer has picked " << comp_pick << "\nThe bottles remaining are: " << bottles << endl;
        }
        cout << "You will have to pick up the last..you are loser";
    }
    else
    {
        bool win = 0;
        comp_pick = 1;
        bottles -= comp_pick;
        while (bottles != 1)
        {

            cout << "Computer has picked " << comp_pick << "\nThe bottles remaining are: " << bottles << endl;
            cout << "How many you would like to pick up?" << endl;
            cin >> user_pick;
            while (user_pick > 4 || user_pick < 1)
            {
                cout << "Please pick bottles between 1 and 4 (inclusive)" << endl;
                cin.clear();
                cin.ignore();
                cin >> user_pick;
            }
            if (user_pick + comp_pick != 5 && !win)
            {
                comp_pick = 5 - user_pick - comp_pick;
                win = 1;
            }
            else
            {
                comp_pick = 5 - user_pick;
            }

            bottles -= user_pick + comp_pick;
        }
        cout << "You will have to pick up the last..you are loser";
    }

    return 0;
}