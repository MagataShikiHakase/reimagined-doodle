#include <iostream>

using namespace std;

bool isValidDate(int month, int day, int year);
int calculateAge(int cYear, int bYear, int cMonth, int bMonth, int cDay, int bDay);

int main()
{
	while (true)
	{
		//Birthday
		int birthMonth = 0, birthDay = 0, birthYear = 0;
		bool check1 = isValidDate(birthMonth, birthDay, birthYear);
		do
		{
			cout << "Enter your birthday (MM DD YYYY)" << endl;
			cin >> birthMonth >> birthDay >> birthYear;
			check1 = isValidDate(birthMonth, birthDay, birthYear);
		} while (check1 != true);

		//Current day
		int currentMonth = 0, currentDay = 0, currentYear = 0;
		bool check2 = isValidDate(currentMonth, currentDay, currentYear);
		do
		{
			cout << "Enter your CURRENT day (MM DD YYYY)" << endl;
			cin >> currentMonth >> currentDay >> currentYear;
			check2 = isValidDate(currentMonth, currentDay, currentYear);
		} while (check2 != true);

		//Age
		int age = calculateAge(currentYear, birthYear, currentMonth, birthMonth, currentDay, birthDay);
		cout << "Your age: " << age << endl;
	}
}

bool isValidDate(int month, int day, int year)
{
	if (month > 0 && month <= 12 && day > 0 && day <= 31 && year >= 1990 && year <= 2022) 
		return true;
	else
		return false;
}

int calculateAge(int cYear, int bYear, int cMonth, int bMonth, int cDay, int bDay)
{
	int age;
	if (cMonth - bMonth > 0)
		age = cYear - bYear;
	else if (cMonth - bMonth < 0)
		age = cYear - bYear - 1;
	else if (cMonth - bMonth == 0)
	{
		if (cDay - bDay >= 0)
			age = cYear - bYear;
		else if (cDay - bDay < 0)
			age = cYear - bYear - 1;
	}
	return age;
}