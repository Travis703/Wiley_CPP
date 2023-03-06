#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int userNum;
    int divNum;
   
    cin.exceptions(ios::failbit); // Allow cin to throw exceptions

    try
    {
        cin >> userNum >> divNum;
        if (divNum == 0)
        {
            throw runtime_error("Runtime Exception: Divide by zero!");
        }
        cout << userNum / divNum << endl;
    }
    catch (ios_base::failure &er)
    {
        cout << "Input Exception: basic_ios::clear: iostream error" << endl;
    }

    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
