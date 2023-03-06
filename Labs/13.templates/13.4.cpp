#include <string>
#include <iostream>

using namespace std;

template <typename g>

int CheckOrder(g a, g b, g c, g d)
{
   if (a > b && b > c && c > d)
   {
      return 1;
   }
   else if (a < b && b < c && c < d)
   {
      return -1;
   }
   return 0;
}

int main()
{
   // Read in four strings
   string stringArg1, stringArg2, stringArg3, stringArg4;
   cin >> stringArg1;
   cin >> stringArg2;
   cin >> stringArg3;
   cin >> stringArg4;
   // Check order of four strings
   cout << "Order: " << CheckOrder(stringArg1, stringArg2, stringArg3, stringArg4) << endl;

   // Read in four doubles
   double doubleArg1, doubleArg2, doubleArg3, doubleArg4;
   cin >> doubleArg1;
   cin >> doubleArg2;
   cin >> doubleArg3;
   cin >> doubleArg4;
   // Check order of four doubles
   cout << "Order: " << CheckOrder(doubleArg1, doubleArg2, doubleArg3, doubleArg4) << endl;

   return 0;
}