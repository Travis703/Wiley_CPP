#include "MileageTrackerNode.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    // References for MileageTrackerNode objects
    MileageTrackerNode *headNode;
    MileageTrackerNode *currNode;
    MileageTrackerNode *lastNode;

    double miles;
    string date;
    int i;
    int num;

    headNode = new MileageTrackerNode();
    lastNode = headNode;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> miles >> date;
        currNode = new MileageTrackerNode(miles, date);
        lastNode->InsertAfter(currNode);
        lastNode = currNode;
    }

    currNode = headNode->GetNext();
    for (int i = 0; i < num; i++)
    {

        currNode->PrintNodeData();
        lastNode = currNode;
        currNode = currNode->GetNext();
    }

    delete headNode;
}