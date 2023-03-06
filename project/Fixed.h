#ifndef FIXEDH
#define FIXEDH
#include <string>
#include <utility>
#include "Bank.h"

class Fixed : public Bank
{
public:
    Fixed();
    Fixed(int type,long account_number, long BSB, std::string bank_name, std::string date_opened, double balance, int deposit, int tenure);
    void calculateInterest();
    int getDeposit();
    int getTenure();
    
    std::pair<int,int> getOther();
private:
    int deposit, tenure;
};
#endif