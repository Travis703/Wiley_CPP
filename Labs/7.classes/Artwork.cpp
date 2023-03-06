#include "Artwork.h"
#include <iostream>

// TODO: Define default constructor
Artwork::Artwork()
{
    title = "unknown";
    yearCreated = -1;
}

Artwork::Artwork(string a, int b, Artist c)
{
    title = a;
    yearCreated = b;
    artist = c;
}

string Artwork::GetTitle() const
{
    return title;
}
int Artwork::GetYearCreated() const
{
    return yearCreated;
}
void Artwork::PrintInfo() const
{
    artist.PrintInfo();
    cout << "Title: " << GetTitle() << ", " << GetYearCreated() << endl;
}
