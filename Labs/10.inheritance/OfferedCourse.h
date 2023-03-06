#ifndef OFFERED_COURSEH
#define OFFERED_COURSEH

#include "Course.h"

class OfferedCourse : public Course
{
    // TODO: Declare private data members
private:
    string name, location, time;

public:
    void SetInstructorName(string a);
    void SetLocation(string a);
    void SetClassTime(string a);

    string GetInstructorName();
    string GetLocation();
    string GetClassTime();
};

#endif