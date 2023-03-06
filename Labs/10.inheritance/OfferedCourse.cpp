#include "OfferedCourse.h"

void OfferedCourse::SetClassTime(string a)
{
    time = a;
}
void OfferedCourse::SetInstructorName(string a)
{
    name = a;
}
void OfferedCourse::SetLocation(string a)
{
    location = a;
}

string OfferedCourse::GetClassTime()
{
    return time;
}
string OfferedCourse::GetInstructorName()
{
    return name;
}
string OfferedCourse::GetLocation()
{
    return location;
}
