#include <iostream>

using namespace std;

void selectionsort(int data[]);

const int SIZE = 10;
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
    selectionsort(data);
    cout << endl;


    for (int i : data)
    {
        cout << i << "  ";
    }
    return 0;
}

void selectionsort(int data[])
{

    for (int i = 0; i < SIZE - 1; i++)
    {
        int small = i;
        for (int k = i + 1; k < SIZE; k++)
        {
            if (data[k] < data[small])
            {
                small = k;
            }
        }

        int temp = data[i];
        data[i] = data[small];
        data[small] = temp;
        for (int j = 0; j < SIZE; j++)
        {
            cout << data[j] << "  ";
        }
        cout << endl;
    }
}