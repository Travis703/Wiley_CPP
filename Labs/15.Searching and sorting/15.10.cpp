#include <iostream>

using namespace std;

// TODO: Write a void function SelectionSortDescendTrace() that takes
//       an integer array and the number of elements in the array as arguments,
//       and sorts the array into descending order.
void SelectionSortDescendTrace(int numbers[], int numElements)
{

    for (int i = 0; i < numElements - 1; i++)
    {
        int j = i;
        for (int k = i + 1; k < numElements; k++)
        {
            if (numbers[i] < numbers[k] && numbers[k] > numbers[j])
            {
                j = k;
            }
        }

        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;

        for (int m = 0; m < numElements; m++)
        {
            cout << numbers[m] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int input, i = 0;
    int numElements = 0;
    int numbers[10];

    for (int i = 0; i < 10; i++)
    {
        cin >> input;
        if (input == -1)
        {
            break;
        }
        numbers[i] = input;
        numElements++;
    }
    SelectionSortDescendTrace(numbers, numElements);

    return 0;
}