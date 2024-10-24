#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateCircumference(double diameter);
double calculateSurfaceArea(double semidiameter);
double mean(double a, double b, double c, double e);
double standardDeviation(double a, double b, double c, double e);

const double PI = 3.141592;

int main()
{
	//Part 1-1
	double diameterOfEarth = 8000, diameterOfSun = 100 * 8000;
	cout << "The circumference of the Earth: " << calculateCircumference(diameterOfEarth) << "miles" << endl;
	cout << "The circumference of the Sun: " << calculateCircumference(diameterOfSun) << "miles" << endl;
	//Part 1-1-a
	cout << "There are about " << calculateCircumference(diameterOfEarth) / 1000 << " hours in a day." << endl;
	//Part 1-2
	double semidiameterOfEarth = diameterOfEarth / 2, semidiameterOfSun = diameterOfSun / 2;
	cout << "The surface area of the Earth: " << calculateSurfaceArea(semidiameterOfEarth) << "miles^2" << endl;
	cout << "The surface area of the Sun: " << calculateSurfaceArea(semidiameterOfSun) << "miles^2" << endl;
	//Part 1-2-a
	double surfaceAreaOfJapan = 150000;
	cout << "The surface area of the earth is about " << calculateSurfaceArea(semidiameterOfEarth) / surfaceAreaOfJapan << " times the surface area of Japan." << endl;

	//Part 2
	double x1, x2, x3, x4;
	cout << "Enter four numbers" << endl;
	cin >> x1 >> x2 >> x3 >> x4;
	cout << "The mean of the four numbers: " << mean(x1, x2, x3, x4) << endl;
	cout << "The standard deviation of the four numbers: " << standardDeviation(x1, x2, x3, x4) << endl;
}

double calculateCircumference(double diameter)
{
	double circumference = PI * diameter;
	return circumference;
}
double calculateSurfaceArea(double semidiameter)
{
	double surfaceArea = 4 * pow(semidiameter, 2) * PI;
	return surfaceArea;
}
double mean(double a, double b, double c, double d)
{
	double x = (a + b + c + d) / 4;
	return x;
}
double standardDeviation(double a, double b, double c, double d)
{
	double x = sqrt((pow(a - mean(a, b, c, d), 2) + pow(b - mean(a, b, c, d), 2) + pow(c - mean(a, b, c, d), 2) + pow(d - mean(a, b, c, d), 2)) / 4);
	return x;
}