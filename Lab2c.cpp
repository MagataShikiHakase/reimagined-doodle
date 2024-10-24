#include <iostream>
using namespace std;
int main()
{
	cout << "Enter the gasoline's capacity of your car in gallon." << endl;
	double capacity;
	cin >> capacity;
	double costPerGallon = 3.90;
	cout << "Enter the fuel efficiency of your car in mile/gallon." << endl;
	double fuelEfficiency;
	cin >> fuelEfficiency;
	cout << "Enter how many people you want to split the gas money with." << endl;
	double people;
	cin >> people;
	cout << "Yous ones have to pay $" << capacity * costPerGallon / people << "per person." << endl;
	cout << "And, your car has a mileage of " << capacity * fuelEfficiency << "miles." << endl;
	return 0;
}