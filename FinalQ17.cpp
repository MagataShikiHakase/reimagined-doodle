#include <iostream>

using namespace std;

void randomName(string str);

int main()
{
	srand(time(0));
	string firstName, middleName, lastName;
	string fullNames[5] =
	{
		"John Doe Smith",
		"Kate Garry Hudson",
		"Tina Stamatina Fey",
		"Hugh Mungo Grant",
		"Uma Karuna Thurman"
	};
	
	for (int i = 0; i < 5; i++)
	{
		cout << "Your first name is " << fullNames[i].substr(0, fullNames[i].find(" ")) << " with a length of " << fullNames[i].substr(0, fullNames[i].find(" ")).length() << endl;
		cout << "Your middle name is " << fullNames[i].substr(fullNames[i].find(" ") + 1, fullNames[i].find(" ", fullNames[i].find(" ") + 1) - fullNames[i].find(" ") - 1) << " with a length of " << fullNames[i].substr(fullNames[i].find(" ") + 1, fullNames[i].find(" ", fullNames[i].find(" ") + 1) - fullNames[i].find(" ")).length() - 1 << endl;
		cout << "Your last name is " << fullNames[i].substr(fullNames[i].find(" ", fullNames[i].find(" ") + 1) + 1, fullNames[i].length() - fullNames[i].find(" ", fullNames[i].find(" ") + 1)) << " with a length of " << fullNames[i].substr(fullNames[i].find(" ", fullNames[i].find(" ") + 1) + 1, fullNames[i].length() - fullNames[i].find(" ", fullNames[i].find(" ") + 1)).length() << endl;
		cout << "Your initials are " << fullNames[i].substr(0, 1) << fullNames[i].substr(fullNames[i].find(" ") + 1, 1) << fullNames[i].substr(fullNames[i].find(" ", fullNames[i].find(" ") + 1) + 1, 1) << ". The length of your entire name (including spaces) is " << fullNames[i].length() << "." << endl;
		cout << "A random sequence of 5 letters in your name is "; 
		randomName(fullNames[i]);
	    cout <<  "." << endl << endl;
	}
}
void randomName(string str)
{
	for (int i = 0; i < 5; i++)
	{
		int num = rand() % str.length();
		cout << str[num];
		str.replace(num, 1, "");
	}
}
