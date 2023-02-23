#include <iostream>
#include <iomanip>
#include <cmath>
#include "Car.h"
using namespace std;

void Car::SetModelYear(int userYear)
{
   modelYear = userYear;
}

int Car::GetModelYear() const
{
   return modelYear;
}

void Car::SetPurchasePrice(int a)
{
   purchasePrice = a;
}
// TODO: Implement SetPurchasePrice() function

// TODO: Implement GetPurchasePrice() function

int Car::GetPurchasePrice()
{
   return purchasePrice;
}

void Car::CalcCurrentValue(int currentYear)
{
   double depreciationRate = 0.15;
   int carAge = currentYear - modelYear;

   // Car depreciation formula
   currentValue = purchasePrice * pow((1 - depreciationRate), carAge);
}

void Car::PrintInfo()
{

   cout << "Car's information:" << endl;
   cout << "  Model year: " << GetModelYear() << endl;
   cout << "  Purchase price: $" << GetPurchasePrice() << endl;
   cout << fixed << setprecision(0) << "  Current value: $" << currentValue << endl;
}
