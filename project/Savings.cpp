#include "Savings.h"
#include <iostream>
#include <string>
#include <utility>
using namespace std;

Savings::Savings()
{
    cout << "dsfg" << endl;
}
Savings::Savings(int type, long account_number, long BSB, string bank_name, string date_opened, double balance, bool salary, int min_bal) : Bank(type, account_number, BSB, bank_name, date_opened, balance)
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