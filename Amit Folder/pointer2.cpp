#include <iostream>
using namespace std;

int main() {
   int someInt;
   int* valPointer;

   someInt = 5;
   cout << "someInt address is " << &someInt << endl;

   valPointer = &someInt;        
   cout << "valPointer is " << valPointer << endl;
   cout << "*valPointer is " << *valPointer << endl;

   return 0;
}