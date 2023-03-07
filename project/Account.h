#ifndef BANKH
#define BANKH
#include <string>
#include <utility>


class Customer;
class Account
{
public:
    Account();
    Account(int type,long account_number, long BSB, std::string bank_name, std::string date_opened, double balance);
   
    long getAccountNumber();
    long getBSB();
    std::string getBankName();
    std::string getDateOpened();
    double getBalance();
    int getType();
    virtual void calculateInterest() = 0;
    virtual std::pair<int,int> getOther()=0;
    virtual void printDetails()=0;

    double getInterestEarned();
    void setInterestEarned(double interest);

private:
    long account_number, BSB;
    int type;
    std::string bank_name, date_opened;
    double balance;
    double interestEarned;
    Customer *customer;

};
#endif