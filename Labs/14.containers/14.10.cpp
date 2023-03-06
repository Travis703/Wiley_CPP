#include "ListItem.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    // TODO: Declare a list called shoppingList of type ListItem
    list<ListItem> lis;
    string item;
    getline(cin, item);
    while (item != "-1")
    {
        lis.push_back(item);
        getline(cin, item);
    }

    
    for (ListItem i : lis)
    {
        i.PrintNodeData();
    }


    return 0;
}