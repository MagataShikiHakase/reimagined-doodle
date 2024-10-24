#include <iostream>
#include <iomanip>
using namespace std;

const int STUDENTNUM = 4;
const int GRADENUM = 3;

int main()
{
	int studentGrade[STUDENTNUM][GRADENUM] =
	{
		{10,9,90},
		{8,7,75},
		{8,8,80},
		{10,10,100}
	};
	cout << setw(20) << "Lab 1a  " << "Proj. 1  " << "Exam 1" << endl << endl;
	for (int i = 0; i < STUDENTNUM; i++)
	{
		cout << "Student " << i+1 << "     ";
		for (int j = 0; j < GRADENUM; j++)
		{
			cout << left << setw(8) << studentGrade[i][j];
		}
		cout << endl;
	}
}
