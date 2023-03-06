#ifndef COURSEH
#define COURSEH

#include <iostream>
#include <string>

using namespace std;

class Course
{
    // TODO: Declare private data members
private:
    string title, num;

public:
    void SetCourseNumber(string a);
    void SetCourseTitle(string);
    string GetCourseNumber();
    string GetCourseTitle();
    void PrintInfo();
};

#endif
