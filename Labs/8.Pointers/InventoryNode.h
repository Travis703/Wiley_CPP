#include <iostream>
#include <string>
using namespace std;

class InventoryNode
{
private:
    string item;
    int numberOfItems;
    InventoryNode *nextNodeRef;

public:
    // Constructor
    InventoryNode()
    {
        this->item = "";
        this->numberOfItems = 0;
        this->nextNodeRef = NULL;
    }

    // Constructor
    InventoryNode(string itemInit, int numberOfItemsInit)
    {
        this->item = itemInit;
        this->numberOfItems = numberOfItemsInit;
        this->nextNodeRef = NULL;
    }

    // Constructor
    InventoryNode(string itemInit, int numberOfItemsInit, InventoryNode nextLoc)
    {
        this->item = itemInit;
        this->numberOfItems = numberOfItemsInit;
        this->nextNodeRef = &nextLoc;
    }

    void InsertAtFront(InventoryNode *start, InventoryNode *end)
    {
        InventoryNode *temp = start->nextNodeRef;
        start->nextNodeRef = end;
        end->nextNodeRef = temp;
    }

    // Get the next node
    InventoryNode *GetNext()
    {
        return this->nextNodeRef;
    }

    // Print node data
    void PrintNodeData()
    {
        cout << this->numberOfItems << " " << this->item << endl;
    }
};