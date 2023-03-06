#include "Course.h"

void Course::SetCourseNumber(string a)
{
    num = a;
}
void Course::SetCourseTitle(string a)
{
    title = a;
}

string Course::GetCourseNumber()
{
    return num;
}
string Course::GetCourseTitle()
{
    return title;
}
void Course::PrintInfo()
{
    cout << "Course Information:" << endl;
    cout << "   Course Number: " << GetCourseNumber() << endl;
    cout << "   Course Title: " << GetCourseTitle() << endl;
}
