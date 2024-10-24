#include <iostream>
#include <vector>
using namespace std;

class Person
{
public:
	string name;
	int age;

	void showInfo()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl << endl;;
	}
};

class testResult
{
public:
	int test1, test2, final;
	void testScore()
	{
		cout << "The score of test1: " << test1 << endl;
		cout << "The score of test2: " << test2 << endl;
		cout << "The score of final: " << final << endl << endl;
	}
};

class grade
{
public:
	int average;
	void grading()
	{
		cout << "The score of average: " << average << endl;
		if (average <= 100 && average >= 90)
			cout << "Your grade: " << "A" << endl;
		else if (average < 90 && average >= 80)
			cout << "Your grade: " << "B" << endl;
		else if (average < 80 && average >= 70)
			cout << "Your grade: " << "C" << endl;
		else if (average < 70 && average >= 60)
			cout << "Your grade: " << "D" << endl;
		else if (average < 60 && average >= 50)
			cout << "Your grade: " << "E" << endl;
		else if (average < 50 && average >= 0)
			cout << "Your grade: " << "F" << endl;
	}
};

int main()
{
	Person me;
	me.name = "Yuma Fukazawa";
	me.age = 20;
	me.showInfo();

	testResult Me;
	Me.test1 = 90;
	Me.test2 = 75;
	Me.final = 80;
	Me.testScore();

	grade ME;
	ME.average = (Me.test1 + Me.test2 + Me.final) / 3;
	ME.grading();
}