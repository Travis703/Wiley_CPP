#include <iostream>
#include <iomanip>
#include "Team.h"
using namespace std;

// TODO: Implement mutator functions -
//       SetName(), SetWins(), SetLosses()
void Team::SetLosses(int a)
{
    losses = a;
}
void Team::SetName(string a)
{
    name = a;
}
void Team::SetWins(int a)
{
    wins = a;
}
// TODO: Implement accessor functions -
//       GetName(), GetWins(), GetLosses()

string Team::GetName()
{
    return name;
}
int Team::GetLosses()
{
    return losses;
}
int Team::GetWins()
{
    return wins;
}

// TODO: Implement GetWinPercentage()
double Team::GetWinPercentage()
{
    return static_cast<double>(wins) / (wins + losses);
}

// TODO: Implement PrintStanding()
void Team::PrintStanding()
{
    cout << fixed << setprecision(2) << "Win percentage: " << GetWinPercentage() << endl;
    cout << ((GetWinPercentage() > 0.5) ? ("Congratulations, Team " + GetName() + " has a winning average!") : ("Team " + GetName() + " has a losing average.")) << endl;
}