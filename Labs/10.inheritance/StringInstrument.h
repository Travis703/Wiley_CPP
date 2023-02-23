#ifndef STR_INSTRUMENTH
#define STR_INSTRUMENTH

#include "Instrument.h"

class StringInstrument : public Instrument
{

private:
    int numstrings, numfrets;
    bool isbowed;

public:
    void SetNumOfStrings(int a);
    void SetNumOfFrets(int a);
    void SetIsBowed(bool a);

    int GetNumOfStrings();
    int GetNumOfFrets();
    bool GetIsBowed();

};

#endif
