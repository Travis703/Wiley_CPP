#ifndef SAVINGH
#define SAVINGH
#include <string>
#include "Bank.h"

class Savings : public Bank
{
private:
    bool salary;
    int min_bal;

public:
    Savings();
    Savings(int type,long account_number, long BSB, std::string bank_name,std::string date_opened, double balance,bool salary, int min_bal);
    bool getSalary();
    int getMinBalance();
    void calculateInterest();
    std::pair<int,int> getOther();
};
#endif