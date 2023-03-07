#include "Customer.h"
#include "FileStorageDao.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int Customer::customer_counter = FileStorageDao::lastID();
Customer::Customer()
{
    cout << "here" << endl;
}

Customer::Customer(string name, int age, string DOB, int mobile, string passport)
{
    customer_counter++;
    this->id = customer_counter;
    this->name = name;
    this->age = age;
    this->DOB = DOB;
    mobile_number = mobile;
    passport_number = passport;
    bank_account = nullptr;
}
Customer::Customer(int id, string name, int age, string DOB, int mobile, string passport)
{

    this->id = id;
    this->name = name;
    this->age = age;
    this->DOB = DOB;
    mobile_number = mobile;
    passport_number = passport;
    bank_account = nullptr;
}
Customer::Customer(string name, int age, string DOB, int mobile, string passport, Account *bank)
{
    customer_counter++;
    this->id = customer_counter;
    this->name = name;
    this->age = age;
    this->DOB = DOB;
    mobile_number = mobile;
    passport_number = passport;
    bank_account = bank;
}
Customer::Customer(int id, string name, int age, string DOB, int mobile, string passport, Account *bank)
{

    this->id = id;
    this->name = name;
    this->age = age;
    this->DOB = DOB;
    mobile_number = mobile;
    passport_number = passport;
    bank_account = bank;
}
void Customer::addAccount(Account *b)
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
Account *Customer::getAccount()
{
    return bank_account;
}

void Customer::printDetails()
{
    
    cout << left << setfill(' ') << setw(4) << "ID "
         << setw((getName().length()>6)? (getName().length() + 3):7) << "| Name "
         << setw(3) << "| Age "
         << setw(((getDOB().length())>5)? (getDOB().length() + 3):8) << "| DOB "
         << setw(13) << "| Mobile# "
         << setw((getPassport().length()>11)?(getPassport().length() + 3):14) << "| Passport# "
         << endl;

    cout << setfill(' ') << getID() << " | "
         << setw((getName().length()>6)? (getName().length()):4) << getName() << " | "
         << setw(3) << getAge() << " | "
         << setw(((getDOB().length())>5)? (getDOB().length()):5) << getDOB() << " | "
         << setw(10) << getMobile() << " | "
         << setw((getPassport().length()>11)?(getPassport().length()):11) << getPassport() << endl;

    if (getAccount())
    {
        getAccount()->printDetails();
    }
    else
    {
        cout << "We have no bank account linked to this customer.";
    }
    cout << endl;
}
