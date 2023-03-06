#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string studentName;
    double studentGrade;

    map<string, double> studentGrades;

    // Students' grades (pre-entered)
    studentGrades.emplace("Harry Rawlins", 84.3);
    studentGrades.emplace("Stephanie Kong", 91.0);
    studentGrades.emplace("Shailen Tennyson", 78.6);
    studentGrades.emplace("Quincy Wraight", 65.4);
    studentGrades.emplace("Janine Antinori", 98.2);


    getline(cin, studentName);
    cin >> studentGrade;
    cout << studentName << "'s original grade: " << studentGrades.at(studentName) << endl;
    cout << studentName << "'s new grade: " << studentGrade << endl;
    return 0;
}