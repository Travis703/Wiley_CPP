#ifndef FILESTORAGEH
#define FILESTORAGEH
#include <string>
#include <vector>
#include "idao.h"

class FileStorageDao:public idao{
    public:
    void saveAllCustomers(vector<Customer*> data);
    vector<Customer*> retrieveAllCustomers();
    void printAllCustomers();
    static int lastID();
    static vector<string> split(string s, char delim);
    
};
#endif