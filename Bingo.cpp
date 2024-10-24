#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

void fill_card(int* bingo_card);
void print_card(int* bingo_card);
bool is_on_card(int* bingo_card, int value);

int main()
{
	srand(time(0));
	int bingo_card[5][5];
	int guessedNum;
	cout << "Bingo card:" << endl;
	fill_card((int*)bingo_card);
	print_card((int*)bingo_card);
	cout << "Enter the number." << endl;
	while (true)
	{
		cin >> guessedNum;
		bool check = is_on_card((int*)bingo_card, guessedNum);
		if (check == true)
		{
			cout << "Hit!" << endl;
			break;
		}
		else
			cout << "Miss" << endl;
	}
}
void fill_card(int* bingo_card)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int* ptr = bingo_card + (i * 5) + j;
			*ptr = rand() % 100;
		}
	}
}
void print_card(int* bingo_card)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int* ptr = bingo_card + (i * 5) + j;
			cout << setw(4) << *ptr;
		}
		cout << endl;
	}
}
bool is_on_card(int* bingo_card, int value)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int* ptr = bingo_card + (i * 5) + j;
			if (value == *ptr)
			{
				return true;
			}
		}
	}
	return false;
}
