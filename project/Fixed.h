#ifndef FIXEDH
#define FIXEDH
#include <string>
#include <utility>
#include "Account.h"
template <typename t1>
int countNumber(t1 num);

class Fixed : public Account
{
public:
    Fixed();
    Fixed(int type,long account_number, long BSB, std::string bank_name, std::string date_opened, double balance, int deposit, int tenure);
    void calculateInterest();
    int getDeposit();
    int getTenure();
    void printDetails();
    std::pair<int,int> getOther();
private:
    int deposit, tenure;
};
#endif