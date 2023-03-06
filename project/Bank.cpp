#include "Bank.h"
#include <iostream>
using namespace std;
Bank::Bank()
{
    cout << "d" << endl;
}
Bank::Bank(int type,long account_number, long BSB, string bank_name, string date_opened, double balance)
{
    this->type=type;
    this->account_number = account_number;
    this->BSB = BSB;
    this->bank_name=bank_name;
    this->date_opened=date_opened;
    this->balance = balance;
}

void Bank::setInterestEarned(double interest)
{
    interestEarned = interest;
}
double Bank::getInterestEarned()
{
    return interestEarned;
}
string Bank::getDateOpened()
{
    return date_opened;
}
double Bank::getBalance()
{
    return balance;
}
long Bank::getAccountNumber()
{
    return account_number;
}
long Bank::getBSB()
{
    return BSB;
}
string Bank::getBankName()
{
    return bank_name;
}