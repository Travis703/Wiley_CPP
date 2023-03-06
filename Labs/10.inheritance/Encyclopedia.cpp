#include "Encyclopedia.h"
#include <iostream>

// Define functions declared in Encyclopedia.h
void Encyclopedia::SetEdition(string a)
{
    edition = a;
}
void Encyclopedia::SetNumPages(int a)
{
    num = a;
}

string Encyclopedia::GetEdition()
{
    return edition;
}
int Encyclopedia::GetNumPages()
{
    return num;
}
void Encyclopedia::PrintInfo()
{
    Book::PrintInfo();
    cout << "   Edition: " << GetEdition() << endl;
    cout << "   Number of Pages: " << GetNumPages() << endl;
}