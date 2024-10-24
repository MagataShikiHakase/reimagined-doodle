#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

bool isValidNumber(int num);
void upOrDown(int x, int y);

int main()
{
	srand(time(0));
	int userNum = 100, cpuNum, userAnswer, cpuAnswer, turn, range1 = 1, range2 = 100;
	bool checkRange = isValidNumber(userNum);
	//user decides number
	do
	{
		cout << "Enter a number which is your answer (1-99) ";
		cin >> userNum;
		checkRange = isValidNumber(userNum);
	} while (checkRange == false);
	cout << "Guess the CPU's number before the CPU match the numbers you set" << endl;

	//cpu decides number
	cpuNum = rand() % 100 + 1;

	//decide turn
	turn = rand() % 2;

	cout << "Player's answer" << setw(25) << "CPU's answer" << endl << endl;

	cpuAnswer = (range2 + range1) / 2;

	if (turn == 0)
	{
		cout << setw(30) << cpuAnswer << endl;
		if (cpuAnswer == userNum)
		{
			cout << endl;
			cout << "\n" << "You lose." << "\n" << "CPU number : " << cpuNum << endl;
			return 0;
		}
		cout << setw(40);
		upOrDown(userNum, cpuAnswer);
		if ((range2 + range1) / 2 > userNum)
			range2 = (range2 + range1) / 2;
		else if ((range2 + range1) / 2 < userNum)
			range1 = (range2 + range1) / 2;
		cpuAnswer = (range2 + range1) / 2;
	}

	//start game
	while (true)
	{
		do
		{
			cin >> userAnswer;
			checkRange = isValidNumber(userAnswer);
			if (checkRange == false)
				cout << "Enter the number (1-99)" << endl;
		} while (checkRange == false);
		

		if (userAnswer == cpuNum)
		{
			cout << endl;
			cout << "Congraturations! You win." << endl;
			return 0;
		}
		upOrDown(cpuNum, userAnswer);

		cout << setw(30) << cpuAnswer << endl;
		if (cpuAnswer == userNum)
		{
			cout << "\n" << "You lose." << "\n" << "CPU number : " << cpuNum << endl;
			return 0;
		}
		cout << setw(40);
		upOrDown(userNum, cpuAnswer);

		//how CPU returns answer
		if ((range2 + range1) / 2 > userNum)
			range2 = (range2 + range1) / 2;
		else if ((range2 + range1) / 2 < userNum)
			range1 = (range2 + range1) / 2;
		cpuAnswer = (range2 + range1) / 2;

	}
}

bool isValidNumber(int num)
{
	if (num >= 1 && num <= 99)
		return true;
	else
		return false;
}
void upOrDown(int x, int y)
{
	if (x > y)
		cout << "more greater" << endl << endl;
	else if (x < y)
		cout << "more smaller" << endl << endl;
}