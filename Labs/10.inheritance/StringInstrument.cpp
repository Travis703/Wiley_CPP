#include "StringInstrument.h"

// TODO: Define mutator functions -
//      SetNumOfStrings(), SetNumOfFrets(), SetIsBowed()
void StringInstrument::SetNumOfStrings(int a)
{
    numstrings = a;
}
void StringInstrument::SetNumOfFrets(int a)
{
    numfrets = a;
}
void StringInstrument::SetIsBowed(bool a)
{
    isbowed = a;
}

int StringInstrument::GetNumOfStrings()
{
    return numstrings;
}
int StringInstrument::GetNumOfFrets()
{
    return numfrets;
}
bool StringInstrument::GetIsBowed()
{
    return isbowed;
}
// TODO: Define accessor functions -
//      GetNumOfStrings(), GetNumOfFrets(), GetIsBowed()
