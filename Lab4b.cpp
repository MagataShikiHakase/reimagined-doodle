#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	float width, length, semidiameter, height, perimeter, area, volume, circumference;
	const float pi = 3.14;
	string shape;
	cout << "Enter what shape do you want to know?" << endl;
	cin >> shape;

	if (shape == "rectangle"){
		cout << "Enter the value of width and length." << endl;
		cin >> width >> length;
		perimeter = 2 * (width + length);
		area = width * length;
		cout << "The rectangle's perimeter is " << perimeter << "cm and area is " << area << "cm^2." << endl;
	}

	else if (shape == "circle") {
		cout << "Enter the value of semidiameter." << endl;
		cin >> semidiameter;
		area = pow(semidiameter, 2) * pi;
		circumference = 2 * semidiameter * pi;
		cout << "The circle's circumference is " << circumference << "cm and area is " << area << "cm^2." << endl;
	}
	else if (shape == "cylinder") {
		cout << "Enter value of semidiameter and height in order." << endl;
		cin >> semidiameter >> height;
		area = 2 * pow(semidiameter, 2) * pi + 2 * semidiameter * height;
		volume = pow(semidiameter, 2) * pi * height;
		cout << "The cylinder's surface area is " << area << "cm^2 and volume is " << volume << "cm^3" << endl;
	}
	else {
		cout << "This program can't handle the shape you entered." << endl;
	}
	return 0;
}