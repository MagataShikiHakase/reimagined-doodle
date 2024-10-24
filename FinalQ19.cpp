#include <iostream>

using namespace std;

int main()
{
	double Labs = 20, Quizzes = 15, Projects = 30, Exams = 25+10*0.9918, ExtraCredit = 5, grade;
	
	grade = Labs + Quizzes + Projects + Exams + ExtraCredit;

	if (grade >= 90)
		cout << "My grade is A." << endl;
	else if (grade < 90 and grade >= 80)
		cout << "My grade is B." << endl;
	else if (grade < 80 and grade >= 70)
		cout << "My grade is C." << endl;
	else if (grade < 70 and grade >= 60)
		cout << "My grade is D." << endl;
	else if (grade < 60 and grade >= 50)
		cout << "My grade is E." << endl;
	else if (grade < 50)
		cout << "My grade is F." << endl;
}