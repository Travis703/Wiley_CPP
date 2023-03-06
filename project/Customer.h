#ifndef CUSTOMERH
#define CUSTOMERH
#include <string>
#include <iostream>

#include "Bank.h"
#include "Savings.h"
#include "Fixed.h"

using namespace std;
class Customer
{
private:
    int id, age, mobile_number;
    string name, passport_number, DOB;
    Bank *bank_account;

public:
    Customer();
    Customer(int id, string name, int age, string DOB,int mobile, string passport);
    Customer(int id, string name, int age, string DOB,int mobile, string passport, Bank *bank);
    void addBank(Bank *bank);
    int getID();
    int getAge();
    int getMobile();
    string getName();
    string getPassport();
    string getDOB();
    Bank *getBank();
    void setName(string s);
    void printDetails();
};

#endif