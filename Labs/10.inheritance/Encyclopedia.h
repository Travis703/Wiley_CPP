#ifndef ENCYCLOPEDIAH
#define ENCYCLOPEDIAH

#include "Book.h"

class Encyclopedia : public Book
{
    // TODO: Declare mutator functions -
    //       SetEdition(), SetNumPages()
public:
    void SetEdition(string a);
    void SetNumPages(int a);
    string GetEdition();
    int GetNumPages();

    void PrintInfo();


private:
    int num;
    string edition;
};

#endif