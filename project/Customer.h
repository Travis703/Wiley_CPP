#ifndef CUSTOMERH
#define CUSTOMERH
#include <string>
#include <iostream>

#include "Account.h"
#include "Savings.h"
#include "Fixed.h"

using namespace std;

class Customer
{
private:
    int id, age, mobile_number;
    string name, passport_number, DOB;
    Account *bank_account;

public:
    static int customer_counter;
    Customer();
    Customer(string name, int age, string DOB, int mobile, string passport);
    Customer(string name, int age, string DOB, int mobile, string passport, Account *bank);
    Customer(int id, string name, int age, string DOB, int mobile, string passport, Account *bank);
    Customer(int id, string name, int age, string DOB, int mobile, string passport);
    void addAccount(Account *bank);
    int getID();
    int getAge();
    int getMobile();
    string getName();
    string getPassport();
    string getDOB();
    Account *getAccount();
    void setName(string s);
    void printDetails();
};

#endif