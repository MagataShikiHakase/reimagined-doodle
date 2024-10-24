#include <iostream>

using namespace std;

int main()
{
	int foldingTime = 0;
	double paperThickness, height;
	cout << "This program displays the distance to the moon by the number of times the paper is folded." << endl;
	cout << "Enter the paper thickness in millimeters.(Paper thickness is basically 0.1 mm)" << endl;
	cin >> paperThickness;
	height = paperThickness;

	while (true)
	{
		height += height;
		foldingTime++;
		if (height > 380000000000)
			break;
	}
	cout << "Fold " << paperThickness << " mm piece of paper " << foldingTime << " times to reach the moon." << endl;
}