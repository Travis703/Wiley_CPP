#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   double dollars,quarters,dimes,nickels,pennies;
   
   cin>>quarters>>dimes>>nickels>>pennies;
   dollars=quarters/4+dimes/10+nickels/20+pennies/100;
   cout << fixed << setprecision(2)<<"Amount: $"<<dollars<<endl;
   
   return 0;
}