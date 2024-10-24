#include <iostream>

using namespace std;

int main()
{
	int unitMatrix[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			unitMatrix[i][j] = 0;
			if (i == j)
				unitMatrix[i][j] = 1;
		}
    }
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << unitMatrix[i][j] << "\t";
		}
		cout << endl;
	}
}