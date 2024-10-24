#include <iostream>

using namespace std;

int main()
{
	double factorialNum, factorialResult = 1;
	cout << "Enter a positive integer" << endl;
	cin >> factorialNum;

	for (int i = 1; i <= factorialNum; i++)
	{
		factorialResult *= i;
	}

	cout << factorialNum << "!= " << factorialResult << endl;
	
	return 0;
}