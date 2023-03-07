#include "Savings.h"
#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
using namespace std;

Savings::Savings()
{
}
Savings::Savings(int type, long account_number, long BSB, string bank_name, string date_opened, double balance, bool salary, int min_bal) : Account(type, account_number, BSB, bank_name, date_opened, balance)
{
    this->salary = salary;
    this->min_bal = min_bal;
    this->calculateInterest();
}
void Savings::calculateInterest()
{
    this->setInterestEarned(this->getBalance() * 0.04);
}
pair<int, int> Savings::getOther()
{
    pair<int, int> p;
    p = make_pair(static_cast<int>(this->getSalary()), this->getMinBalance());
    return p;
}
bool Savings::getSalary()
{
    return salary;
}
int Savings::getMinBalance()
{
    return min_bal;
}

template <typename t1>
int countNumber(t1 num)
{
    string number = to_string(num);
    if (number.find('.') != string::npos)
    {
        number = number.substr(0, number.find('.') + 3);
    }

    return number.length();
}

void Savings::printDetails()
{
    cout << "Your Savings Bank account details are: " << endl;

    cout << left << setfill(' ')
         << setw((getBankName().length() > 6) ? getBankName().length() + 1 : 7) << "Name "
         << setw((countNumber(getAccountNumber()) > 5) ? (countNumber(getAccountNumber())) + 3 : 8) << "| Acc# "
         << setw((countNumber(getBSB()) > 4) ? (countNumber(getBSB()) + 3) : 4) << "| BSB "
         << setw((countNumber(getBalance()) > 8) ? (countNumber(getBalance())) : 7) << "| Balance "
         << setw(((getDateOpened().length()) > 13) ? (getDateOpened().length() + 3) : 14) << "| Date opened "
         << setw((countNumber(getInterestEarned())>8)?countNumber(getInterestEarned())+2:8 ) << "| Interest "
         << setw((getSalary()) ? 6 : 5) << "| Salary "
         << setw(countNumber(getMinBalance()) + 2) << "| Min Bal" << endl;

    cout << setfill(' ') << setw((getBankName().length() > 6) ? getBankName().length() : 6) << getBankName() << " | "
         << setw((countNumber(getAccountNumber()) > 5) ? (countNumber(getAccountNumber())) : 5) << getAccountNumber() << " | "
         << setw((countNumber(getBSB()) > 4) ? (countNumber(getBSB())) : 1) << getBSB() << " | "
         << setw((countNumber(getBalance()) > 8) ? (countNumber(getBalance())) : 7) << getBalance() << " | "
         << setw(((getDateOpened().length()) > 13) ? (getDateOpened().length()) : 11) << getDateOpened() << " | "
         << setw((countNumber(getInterestEarned())>8)?countNumber(getInterestEarned()):8 ) << getInterestEarned() << " | "
         << setw((getSalary()) ? 6 : 5) << ((getSalary() ? "Yes" : "No")) << " | "
         << getMinBalance();
}