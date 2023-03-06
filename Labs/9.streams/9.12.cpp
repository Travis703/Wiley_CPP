#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main()
{

    /* TODO: Declare any necessary variables here. */

    ifstream infile;
    ofstream outfile;
    string name, first, last, s1, s2, s3;
    string grade;
    double avg, m1a = 0.0, m2a = 0.0, fa = 0.0;
    int count = 0;
    cin >> name;
    infile.open(name);
    outfile.open("report.txt");
    infile >> first >> last >> s1 >> s2 >> s3;
    while (!infile.eof())
    {

        avg = (stod(s1) + stod(s2) + stod(s3)) / 3;
        m1a += stod(s1);
        m2a += stod(s2);
        fa += stod(s3);
        if (avg < 60)
        {
            grade = "F";
        }
        else if (avg < 70)
        {
            grade = "D";
        }
        else if (avg < 80)
        {
            grade = "C";
        }
        else if (avg < 90)
        {
            grade = "B";
        }
        else
        {
            grade = "A";
        }
        count++;
        outfile << first + "\t" + last + "\t" + s1 + "\t" + s2 + "\t" + s3 + "\t" + grade << endl;
        infile >> first >> last >> s1 >> s2 >> s3;
    }
    infile.close();
    m1a /= count;
    m2a /= count;
    fa /= count;
    outfile << endl;
    outfile << fixed << setprecision(2) << "Averages: midterm1 " << m1a << ", midterm2 " << m2a << ", final " << fa << endl;
    outfile.close();
    return 0;
}
