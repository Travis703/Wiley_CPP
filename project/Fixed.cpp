#include "Fixed.h"
#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
using namespace std;

Fixed::Fixed()
{
}
Fixed::Fixed(int type, long account_number, long BSB, string bank_name, string date_opened, double balance, int deposit, int tenure) : Account(type, account_number, BSB, bank_name, date_opened, balance)
{
    this->tenure = tenure;
    this->deposit = deposit;
    this->calculateInterest();
}

pair<int, int> Fixed::getOther()
{
    pair<int, int> p;
    p = make_pair(this->getDeposit(), this->getTenure());
    return p;
}
void Fixed::calculateInterest()
{
    this->setInterestEarned(deposit * tenure * 0.08);
}
int Fixed::getDeposit()
{
    return deposit;
}
int Fixed::getTenure()
{
    return tenure;
}
void Fixed::printDetails()
{
    cout << "Your Fixed Bank account details are: " << endl;

    cout << left << setfill(' ')
         << setw((getBankName().length() > 6) ? getBankName().length() + 1 : 7) << "Name "
         << setw((countNumber(getAccountNumber()) > 5) ? (countNumber(getAccountNumber())) + 3 : 8) << "| Acc# "
         << setw((countNumber(getBSB()) > 4) ? (countNumber(getBSB()) + 3) : 4) << "| BSB "
         << setw((countNumber(getBalance()) > 8) ? (countNumber(getBalance())) : 7) << "| Balance "
         << setw(((getDateOpened().length()) > 13) ? (getDateOpened().length() + 3) : 14) << "| Date opened "
         << setw((countNumber(getInterestEarned()) > 8) ? countNumber(getInterestEarned()) + 2 : 8) << "| Interest "
         << setw((countNumber(getDeposit()) > 7) ? countNumber(getDeposit()) : 7) << "| Deposit "
         << "| Tenure" << endl;

    cout << setfill(' ') << setw((getBankName().length() > 6) ? getBankName().length() : 6) << getBankName() << " | "
         << setw((countNumber(getAccountNumber()) > 5) ? (countNumber(getAccountNumber())) : 5) << getAccountNumber() << " | "
         << setw((countNumber(getBSB()) > 4) ? (countNumber(getBSB())) : 1) << getBSB() << " | "
         << setw((countNumber(getBalance()) > 8) ? (countNumber(getBalance())) : 7) << getBalance() << " | "
         << setw(((getDateOpened().length()) > 13) ? (getDateOpened().length()) : 11) << getDateOpened() << " | "
         << setw((countNumber(getInterestEarned()) > 8) ? countNumber(getInterestEarned()) : 8) << getInterestEarned() << " | "
         << setw((countNumber(getDeposit()) > 7) ? countNumber(getDeposit()) : 7) << getDeposit() << " | "
         << getTenure()<<" years";
}
