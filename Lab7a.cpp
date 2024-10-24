#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string str);
string toUpperString(string str);

int main()
{
	string str;
	cout << "Enter string. Enter q, if you want to quit this program." << endl;
	while (true)
	{
		getline(cin, str);
		if (str == "q")
			break;
		str = toUpperString(str);
		bool palindrome = isPalindrome(str);
		if (palindrome == true)
			cout << "String you entered is palindrome." << endl;
		else
			cout << "String you enterd is NOT palindrome." << endl;
	}
	return 0;
}

bool isPalindrome(string str)
{
	bool check;
	for (int i = 0; i <= str.length() - 1; i++)
	{
		if (str[i] == str[str.length() - i - 1])
			check = true;
		else
		{
			check = false;
			break;
		}
	}
	if (check == true)
		return true;
	else
		return false;
}
string toUpperString(string str)
{
	for (int i = 0; str.length() > i; i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}