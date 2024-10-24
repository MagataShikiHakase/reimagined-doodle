#include <iostream>
#include <cctype>
using namespace std;

void checkCharacter(string str);

int main()
{
	string str;
	cout << "Enter a random string" << endl;
	cin >> str;
	checkCharacter(str);
}

void checkCharacter(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
			cout << "Character is a alphabetic" << endl;
		else if (isdigit(str[i]))
			cout << "Character is a digit" << endl;
		else
			cout << "Character is a special" << endl;
	}
}