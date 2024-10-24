#include <iostream>
#include <ctime>
using namespace std;

int larger(int a, int b);
int smaller(int a, int b);
int maxValue(int a, int b, int c, int d, int e, int f);
int minimumValue(int a, int b, int c, int d, int e, int f);

int main()
{
	srand(time(0));
	int value[6][6];
	int sum = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			value[i][j] = rand() % 101;
			sum += value[i][j];
			cout << value[i][j] << "\t";
		}
		cout << endl;
	}
	
	cout << endl;

	for (int i = 0; i < 6; i++)
	{
		int max = maxValue(value[i][0], value[i][1], value[i][2], value[i][3], value[i][4], value[i][5]);
		int minimum = minimumValue(value[i][0], value[i][1], value[i][2], value[i][3], value[i][4], value[i][5]);
		cout << "Max value in row " << i + 1 << ": " << max << endl;
		cout << "Minimum value in row " << i + 1 << ": " << minimum << endl << endl;
	}
	int average = sum / 36;
	cout << endl << "The average of this matrix: " << average;
}

int larger(int a, int b)
{
	int value;
	if (a >= b)
		value = a;
	else
		value = b;
	return value;
}
int smaller(int a, int b)
{
	int value;
	if (a >= b)
		value = b;
	else
		value = a;
	return value;
}
int maxValue(int a, int b, int c, int d, int e, int f)
{
	int max;
	max = larger((larger(larger(a, b), larger(c, d))),(larger(e, f)));
	return max;
}
int minimumValue(int a, int b, int c, int d, int e, int f)
{
	int minimum;
	minimum = smaller((smaller(smaller(a, b), smaller(c, d))), (smaller(e, f)));
	return minimum;
}
