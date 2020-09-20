#include <iostream>

using namespace std;

class Car
{
public:
    string Make;   
    string Model;  
    int YearOfM;   
    int mileage;
    string ifm;
};

int main()
{
    Car Car1;          
    Car1.Make = "BMW";
    Car1.Model = "BMW-5T";
    Car1.YearOfM = 2019;
    Car1.mileage = 1000;
    Car1.ifm = "Made in Califonia";
    return 0;

}