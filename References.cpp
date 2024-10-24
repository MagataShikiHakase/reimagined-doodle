#include <iostream>

using namespace std;

const int arrayNum = 250;
void arraySum(int(&myArray)[arrayNum])
{
	int sum = 0;
	for (int i = 0; i < arrayNum; i++)
	{
		sum += myArray[i];
	}
	cout << "Sum of the number in array: " << sum << endl;
}

int main()
{
	srand(time(0));
	int a[arrayNum];
	for (int i = 0; i < arrayNum; i++)
	{
		a[i] = rand() % 101;
	}

	arraySum(a);
	cout << sizeof(a);
}