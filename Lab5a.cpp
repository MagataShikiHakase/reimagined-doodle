#include <iostream>

using namespace std;

int main()
{
	int num, remainder, sum = 0, i = 1;

	cout << "Enter the positive integer which is under 2147483647 without comma.";
	cin >> num;
	cout <<	endl;

	while (num > 0)
	{
		remainder = num % 10;
		sum += remainder;
		

		cout << "On loop iteration number" << i << endl;
		cout << "Remainder: " << remainder << endl;
		cout << "sum: " << sum << endl;
		num /= 10;
		cout << "Updated input: " << num << "\n" << endl;
		i++;
	}

	return 0;
}