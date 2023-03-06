#include "Customer.h"
#include <iostream>
#include <string>

using namespace std;
Customer::Customer()
{
    cout << "here" << endl;
}
Customer::Customer(int id, string name, int age, string DOB, int mobile, string passport)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->DOB = DOB;
    mobile_number = mobile;
    passport_number = passport;
}
Customer::Customer(int id, string name, int age, string DOB, int mobile, string passport, Bank *bank)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->DOB = DOB;
    mobile_number = mobile;
    passport_number = passport;
    bank_account = bank;
}
void Customer::addBank(Bank *b)
{
    bank_account = b;
}

int Customer::getID()
{
    return id;
}
int Customer::getAge()
{
    return age;
}
void Customer::setName(string s)
{
    name = s;
}
int Customer::getMobile()
{
    return mobile_number;
}
string Customer::getName()
{
    return name;
}
string Customer::getPassport()
{
    return passport_number;
}
string Customer::getDOB()
{
    return DOB;
}
Bank *Customer::getBank()
{
    return bank_account;
}

void Customer::printDetails()
{
    cout << getID() << "\t" << getName() << "\t" << getAge() << "\t";
    cout << getMobile() << "\t" << getPassport() << "\t" << getBank();
}