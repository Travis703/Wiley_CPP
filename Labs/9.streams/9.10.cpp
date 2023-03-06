#include <iostream>
#include <string>

using namespace std;

int DateParser(string month)
{
   int monthInt = 0;

   if (month == "January")
      monthInt = 1;
   else if (month == "February")
      monthInt = 2;
   else if (month == "March")
      monthInt = 3;
   else if (month == "April")
      monthInt = 4;
   else if (month == "May")
      monthInt = 5;
   else if (month == "June")
      monthInt = 6;
   else if (month == "July")
      monthInt = 7;
   else if (month == "August")
      monthInt = 8;
   else if (month == "September")
      monthInt = 9;
   else if (month == "October")
      monthInt = 10;
   else if (month == "November")
      monthInt = 11;
   else if (month == "December")
      monthInt = 12;
   return monthInt;
}

int main()
{
   string in;
   int month = -1;

   while (in != "-1")
   {
      getline(cin, in);
      month = DateParser(in.substr(0, in.find(" ")));

      if (month == 0 || in.find(",") == string::npos)
      {
         continue;
      }
      cout << month << "-" << in.substr(in.find(" ") + 1, in.find(",") - in.find(" ") - 1) << "-" << in.substr(in.find(",") + 2, in.length() - in.find(",") - 1) << endl;
   }

   return 1;
}
