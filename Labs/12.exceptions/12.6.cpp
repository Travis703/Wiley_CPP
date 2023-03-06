#include <iostream>
#include <vector>
#include <stdexcept> // For std::out_of_range
using namespace std;

int main()
{
   vector<string> names = {"Ryley", "Edan", "Reagan", "Henry", "Caius", "Jane", "Guto", "Sonya", "Tyrese", "Johnny"};
   int index;

   cin >> index;
   try
   {
      cout << names.at(index) << endl;
   }
   catch (out_of_range &e)
   {
      cout << "Exception! " << e.what() << endl;
      cout << "The closest name is: " << ((index >= 10) ? names.at(9) : names.at(0)) << endl;
   }
   /* Type your code here. */

   return 0;
}
