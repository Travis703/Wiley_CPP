
#include <iostream>
#include <string>
using namespace std;

int main()
{
   int in;
   string bin;
   cin >> in;
   while (in > 0)
   {
      bin += to_string(in % 2);
      in /= 2;
   }
   cout << bin << endl;
   return 0;
}