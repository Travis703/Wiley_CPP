#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   int num1;
   int num2;
   int num3;
   int num4;

   cin>>num1>>num2>>num3>>num4;
   int product=num1*num2*num3*num4;
   int sum=num1+num2+num3+num4;
   cout<<product<<" "<<sum/4<<endl;
   
   double dproduct=static_cast<double>(num1)*num2*num3*num4;
   double dsum=static_cast<double>(num1)+num2+num3+num4;
   cout<<fixed<<setprecision(3)<<dproduct<<" "<<(dsum)/4<<endl;

   return 0;
}