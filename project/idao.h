#ifndef IDAOH
#define IDAOH
#include <string>
#include <vector>
#include "Customer.h"

class idao
{
public:
    virtual void saveAllCustomers(vector<Customer*> data) = 0;
    virtual vector<Customer*> retrieveAllCustomers() = 0;
};

#endif