#include "Account.h"
#include <iostream>
using namespace std;
Account::Account()
{
    
}
Account::Account(int type,long account_number, long BSB, string bank_name, string date_opened, double balance)
{
    this->type=type;
    this->account_number = account_number;
    this->BSB = BSB;
    this->bank_name=bank_name;
    this->date_opened=date_opened;
    this->balance = balance;
}

void Account::setInterestEarned(double interest)
{
    interestEarned = interest;
}
double Account::getInterestEarned()
{
    return interestEarned;
}
string Account::getDateOpened()
{
    return date_opened;
}
double Account::getBalance()
{
    return balance;
}
long Account::getAccountNumber()
{
    return account_number;
}
long Account::getBSB()
{
    return BSB;
}
string Account::getBankName()
{
    return bank_name;
}
int Account::getType(){
    return type;
}