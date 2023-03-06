#include <string>
#include <vector>
#include <iostream>

using namespace std;

// TODO: Write the partitioning algorithm - pick the middle element as the
//       pivot, compare the values using two index variables l and h (low and high),
//       initialized to the left and right sides of the current elements being sorted,
//       and determine if a swap is necessary
int Partition(vector<string> &userIDs, int i, int k)
{
    string pivot = userIDs[i + (k - i) / 2];
    int l = i, h = k;
    bool done = 0;
    while (!done)
    {
        while (userIDs[l] < pivot)
        {
            l++;
        }
        while (userIDs[h] > pivot)
        {
            h--;
        }
        if (l >= h)
        {
            done = 1;
        }
        else
        {
            string temp = userIDs[l];
            userIDs[l] = userIDs[h];
            userIDs[h] = temp;

            l++;
            h--;
        }
    }
    return h;
}

void Quicksort(vector<string> &userIDs, int i, int k)
{

    int j;

    if (i >= k)
    {
        return;
    }

    j = Partition(userIDs, i, k);

    Quicksort(userIDs, i, j);
    Quicksort(userIDs, j + 1, k);
}

int main()
{
    vector<string> userIDList;
    string userID;

    cin >> userID;
    while (userID != "-1")
    {
        userIDList.push_back(userID);
        cin >> userID;
    }

    // Initial call to quicksort
    Quicksort(userIDList, 0, userIDList.size() - 1);

    for (size_t i = 0; i < userIDList.size(); ++i)
    {
        cout << userIDList.at(i) << endl;
        ;
    }

    return 0;
}