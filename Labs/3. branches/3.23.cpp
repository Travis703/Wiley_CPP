#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    if (num % 100 == 0)
    {
        cout << num << " is not a valid interstate highway number." << endl;
        return 0;
    }
    if (num > 0 && num < 100)
    {
        cout << "I-" << num << " is primary, going " << ((num % 2 == 0) ? "east/west." : "north/south.") << endl;
    }
    else if (num < 1000)
    {
        cout << "I-" << num << " is auxiliary, serving I-" << (num % 100) << ", going " << ((num % 2 == 0) ? "east/west." : "north/south.") << endl;
    }
    else
    {
        cout << num << " is not a valid interstate highway number." << endl;
    }

    return 0;
}