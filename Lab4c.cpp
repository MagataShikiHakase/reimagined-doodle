#include <iostream>
#include <cmath>

using namespace std;

int main()
{
//Part1
	double overSpeed, fine;
	cout << "Enter speed over the limit" << endl;
	cin >> overSpeed;

	if (overSpeed > 0 && overSpeed <= 5) {
		fine = 20.00;
	}
	else if (overSpeed > 5 && overSpeed <= 10) {
		fine = 75.00;
	}
	else if (overSpeed > 10 && overSpeed <= 15) {
		fine = 150.00;
	}
	else {
		fine = 150.00 + int(overSpeed / 15) * 20;
	}
	
	cout << "Your fine is $" << fine << "." << endl;

//Part2
	int side1, side2, side3, square1, square2, square3;
	cout << "Enter side1, side2, and side3:" << endl; 
	cin >> side1>> side2>> side3;
	square1 = pow(side1, 2);
	square2 = pow(side2, 2);
	square3 = pow(side3, 2);

	if (side1 > side2 && side1 > side3) {
		if (square1 == square2 + square3) {
			cout << "The sides defined by side lengths " << side1 << "," << side2 << ",and " << side3 << " is right triangle." << endl;
		}
		else {
			cout << "The sides defined by side lengths " << side1 << "," << side2 << ",and " << side3 << " is NOT right triangle." << endl;
		}
	}
	else if (side2 > side1 && side2 > side3) {
		if (square2 == square1 + square3) {
			cout << "The sides defined by side lengths " << side1 << "," << side2 << ",and " << side3 << " is right triangle." << endl;
		}
		else {
			cout << "The sides defined by side lengths " << side1 << "," << side2 << ",and " << side3 << " is NOT right triangle." << endl;
		}
	}
	else {
		if (square3 == square1 + square2) {
			cout << "The sides defined by side lengths " << side1 << "," << side2 << ",and " << side3 << " is right triangle." << endl;
		}
		
		else {
			cout << "The sides defined by side lengths " << side1 << "," << side2 << ",and " << side3 << " is NOT right triangle." << endl;
		}
	}
	return 0;
}
