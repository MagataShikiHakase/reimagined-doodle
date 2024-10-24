#include <iostream>
#include <ctime>

using namespace std;

int d20DiceRoll(int a);
int d4DiceRoll(int b);

int main()
{
	srand(time(0));

	int num1 = 0, num2 = 0, counter = 1;
	int d20 = d20DiceRoll(num1), d4 = d4DiceRoll(num2);
	
	do 
	{
		cout << counter << "\t" << d20DiceRoll(num1) << "\t" << d4DiceRoll(num2) << endl;
		counter++;
	} 
	while (d20DiceRoll(num1) != 1 || d4DiceRoll(num2) != 1);

	cout << "It took " << counter << "time(s) for both icosahedral and tetrahedral dice to roll a 1.";
}

int d20DiceRoll(int a)
{
	a = rand() % 20 + 1;
	return a;
}

int d4DiceRoll(int b)
{
	b = rand() % 4 + 1;
	return b;
}
