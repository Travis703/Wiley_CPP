#ifndef TEAMH
#define TEAMH

#include <string>

using namespace std;

class Team
{
    // TODO: Declare private data members - name, wins, losses
private:
    string name;
    int wins, losses;

public:
    void SetName(string a);

    void SetWins(int a);

    void SetLosses(int a);

    // TODO: Declare mutator functions -
    //       SetName(), SetWins(), SetLosses()
    string GetName();
    int GetWins();
    int GetLosses();
    // TODO: Declare accessor functions -
    //       GetName(), GetWins(), GetLosses()

    // TODO: Declare GetWinPercentage()
    double GetWinPercentage();
    // TODO: Declare PrintStanding()
    void PrintStanding();
};

#endif