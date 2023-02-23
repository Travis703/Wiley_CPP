#include <iostream>
using namespace std;
#include <iomanip>

int  main(){
    int age,weight,heart_rate,time;
    cin>>age>>weight>>heart_rate>>time;
    double calories;
    calories=(((age*0.2757)+ (weight * 0.03295) + (heart_rate * 1.0781)-75.4991 ) * time )/ 8.368;
    cout << fixed << setprecision(2)<<"Calories: "<<calories<<" calories"<<endl;
    return 0;
}