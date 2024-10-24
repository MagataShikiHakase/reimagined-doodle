#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
//Part 1 - a bit on units of length	
//1)
	cout << "1meter is " << pow(10, 6) << "micrometers." << endl;

//2)
	long long angstromesPerMeter;
	angstromesPerMeter = pow(10, 10);
	cout << "1meter is " << angstromesPerMeter << "Angstromes." << endl;


//Part 2 - string lengths
	cout << "Enter your first name." << endl;
	string firstname1, firstname2;
	firstname1 = "yuma";
	firstname2 = "connor";

	cout << "Yuma's length is " << firstname1.length() << endl;
	cout << "Connor's name length is " << firstname2.length() << endl;

//Part 3 basic arithmethic and currency formatting

	double price1, price2, totalCost;
	price1 = 1.89;
	price2 = 3.29;
	totalCost = price1 + price2;
	cout << "The total cost of 2 goods is $" << fixed << setprecision(2) << totalCost << endl;

	return 0;
}
