#include "Artist.h"
#include <iostream>
#include <string>
using namespace std;

// TODO: Define default constructor
Artist::Artist()
{
    artistName = "unknown";
    birthYear = -1;
    deathYear = -1;
}
Artist::Artist(string a, int b, int c)
{
    artistName = a;
    birthYear = b;
    deathYear = c;
}
string Artist::GetName() const
{
    return artistName;
}
int Artist::GetBirthYear() const
{
    return birthYear;
}
int Artist::GetDeathYear() const
{
    return deathYear;
}

void Artist::PrintInfo() const
{
    cout << "Artist: " << GetName() << " " << ((GetDeathYear() < 0) ? ((GetBirthYear() < 0) ? ("(unknown)") : ("(" + to_string(GetBirthYear()) + " to present)")) : ("(" + to_string(GetBirthYear()) + " to " + to_string(GetDeathYear()) + ")")) << endl;
}