#include <iostream>
#include <string>

using namespace std;

int main()
{
//Part1
	int counter1 = 0;
	char ch1 = 'a';

	while (ch1 != 'q')
	{
		cout << "Enter a character. (q to quite)" << endl;
		cin >> ch1;
		counter1++;
	}

	cout << "Counter: " << counter1 << "\n" << "The final value of character: " << ch1 << endl;


//Part2
	int counter2 = 97;
	char ch2 = 'a';
	/*for (counter2; counter2 <= 122; counter2++)
	{
		cout << "Decimal value: " << counter2 << "\t" << "ASCII char: " << static_cast<char>(counter2) << endl;
	}*/
	for (counter2; counter2 <= 122; counter2++)
	{
		ch2 = counter2;
		cout << "Decimal value: " << counter2 << "\t" << "ASCII char: " << ch2 << endl;
	}
}