#include <iostream>
#include <cmath>

using namespace std;

void calculateRightTriangleArea(double b, double h);
void calculatePerimeter(double b, double h);

int main()
{
	double b, h;
	cout << "Enter the length of base and height of the right triangle" << endl;
	cin >> b >> h;

	calculateRightTriangleArea(b, h);
	calculatePerimeter(b, h);
}

void calculateRightTriangleArea(double b, double h)
{
	cout << "The area of right triangle: " << b * h / 2 << endl;
}
void calculatePerimeter(double b, double h)
{
	cout << "The perimeter of right triangle: " << b + h + sqrt(pow(b, 2) + pow(h, 2)) << endl;
}

