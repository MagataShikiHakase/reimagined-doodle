#include <iostream>
#include <string>

using namespace std;

int stringScore(string str);

int main()
{
	string str;
	cout << "Enter a string." << endl;
	getline(cin, str);
	cout << "Your score: " << stringScore(str) << endl;
	
}

int stringScore(string str)
{
	int score = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'l' || str[i] == 'n' || str[i] == 'o' || str[i] == 'r' || str[i] == 's' || str[i] == 't' || str[i] == 'u')
			score += 1;
		else if (str[i] == 'd' || str[i] == 'g')
			score += 2;
		else if (str[i] == 'b' || str[i] == 'c' || str[i] == 'm' || str[i] == 'p')
			score += 3;
		else if (str[i] == 'f' || str[i] == 'h' || str[i] == 'v' || str[i] == 'w' || str[i] == 'y')
			score += 4;
		else if (str[i] == 'k')
			score += 5;
		else if (str[i] == 'j' || str[i] == 'x')
			score += 8;
		else if (str[i] == 'q' || str[i] == 'z')
			score += 10;
	}
	return score;
}
