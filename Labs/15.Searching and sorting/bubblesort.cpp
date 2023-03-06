#include <iostream>
using namespace std;

const int SIZE = 10;
void bubbleSort(int data[])
{

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int k = 0; k < SIZE - i - 1; k++)
        {
            if (data[k] > data[k + 1])
            {
                int temp = data[k];
                data[k] = data[k + 1];
                data[k + 1] = temp;
            }
        }
        for (int j = 0; j < SIZE; j++)
        {
            cout << data[j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int data[SIZE];
    srand(20);

    for (int i = 0; i < SIZE; i++)
    {
        data[i] = rand() % 23;
    }
    for (int i : data)
    {
        cout << i << "  ";
    }
    cout << endl;
    cout << endl;
    bubbleSort(data);
    cout << endl;

    
    for (int i : data)
    {
        cout << i << "  ";
    }

    return 0;
}