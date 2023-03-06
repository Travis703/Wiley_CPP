#include "Fixed.h"
#include <iostream>
#include <string>
#include <utility>
using namespace std;

Fixed::Fixed(){
    cout<<"ds";
}
Fixed::Fixed(int type,long account_number, long BSB, string bank_name, string date_opened, double balance, int deposit, int tenure):Bank(type,account_number,  BSB, bank_name, date_opened, balance){
    this->tenure=tenure;
    this->deposit=deposit;
    this->calculateInterest();
}

pair<int,int> Fixed::getOther(){
    pair<int,int> p;
    p=make_pair(this->getDeposit(),this->getTenure());
    return p;
}
void Fixed::calculateInterest(){
    this->setInterestEarned(deposit*tenure*0.08);
}
int Fixed::getDeposit(){
    return deposit;
}
int Fixed:: getTenure(){
    return tenure;
}