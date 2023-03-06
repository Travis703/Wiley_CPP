#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Read integers from input and store them in a vector.
// Return the vector.
vector<int> ReadIntegers()
{
    int size;
    cin >> size;
    vector<int> integers(size);
    for (int i = 0; i < size; ++i)
    { // Read the numbers
        cin >> integers.at(i);
    }
    sort(integers.begin(), integers.end());
    return integers;
}
int recursions = 0, comparisons = 0;
int BinarySearch(int target, vector<int> integers, int lower, int upper)
{
    recursions++;
    int mid = (upper + lower) / 2;
    if (lower == upper)
    {
        comparisons += 4;
        return -1;
    }
    if (target == integers.at(mid))
    {
        comparisons++;
        return mid;
    }

    else if (target < integers.at(mid))
    {
        comparisons += 2;
        return BinarySearch(target, integers, lower, mid - 1);
    }
    comparisons++;
    return BinarySearch(target, integers, mid + 1, upper);
}

int main()
{
    int target;
    int index;

    vector<int> integers = ReadIntegers();

    cin >> target;

    index = BinarySearch(target, integers, 0, integers.size() - 1);
    printf("index: %d, recursions: %d, comparisons: %d\n", index, recursions, comparisons);

    return 0;
}
