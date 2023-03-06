#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Define a PrintVector function that prints an vector of plant (or flower) object pointers
void PrintVector(Plant *a)
{
    a->PrintInfo();
    cout << endl;
}
int main()
{
    // TODO: Declare a vector called myGarden that can hold object of type plant pointer
    vector<Plant *> myGarden;
    // TODO: Declare variables - plantName, plantCost, flowerName, flowerCost,
    //       colorOfFlowers, isAnnual
    string input;
    string plantName, flowerName, colorOfFlowers;
    int plantCost, flowerCost;
    string isAnnual;
    cin >> input;

    while (input != "-1")
    {
   
        if (input == "plant")
        {

            Plant *plant = new Plant;
            cin >> plantName >> plantCost;
            plant->SetPlantCost(plantCost);
            plant->SetPlantName(plantName);
            myGarden.push_back(plant);
        }
        else
        {

            Flower *flower = new Flower;

            cin >> flowerName >> flowerCost >> isAnnual >> colorOfFlowers;

            flower->SetPlantCost(flowerCost);
            flower->SetPlantName(flowerName);
            flower->SetColorOfFlowers(colorOfFlowers);
            flower->SetPlantType(((isAnnual == "false") ? 0 : 1));

            myGarden.push_back(flower);
        }

        cin >> input;
       
    }



    for (int i = 0; i < myGarden.size(); i++)
    {
        cout << "Plant " << i + 1 << " Information:" << endl;
        PrintVector(myGarden.at(i));
        delete myGarden.at(i);
    }

    return 0;
}