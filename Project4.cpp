#include <iostream>

using namespace std;

int main()
{
	string answer, guessedAnswer, guessedLetter;
	int playerNum, guessedLetterPosition;

	cout << "Enter 1, if you want to play this game with CPU." << endl;
	cout << "Enter 2, if you want to play this game with one of you friends." << endl;
	cin >> playerNum;

	if (playerNum == 1)
	{
		answer = "america";
	}
	else
	{
		cout << "Enter a word to be guessed: ";
		cin >> answer;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	}

	for (int i = 0; i < answer.length(); i++)
		guessedAnswer.append("*");
	cout << guessedAnswer << endl;

	cout << "Keep entering a character you guess" << endl;

	while (true)
	{
		cin >> guessedLetter;

		if (answer.find(guessedLetter) != -1)
		{
			cout << "You guessed a correct letter!" << endl;
			for (int j = 0; answer.length() > j; j++)
			{
				guessedLetterPosition = answer.find(guessedLetter, j);
				if (guessedLetterPosition != -1)
					guessedAnswer.replace(guessedLetterPosition, 1, guessedLetter);
			}
		}
		else
			cout << "The character you entered isn't within the answer." << endl;

		if (guessedAnswer == answer)
			break;

		cout << guessedAnswer << endl;
	}

	cout << endl;
	cout << "Congraturations! The answer of the word: " << answer << endl;

}