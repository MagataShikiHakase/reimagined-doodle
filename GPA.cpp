#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string firstName, lastName;

    cout << "Enter your First name and Last name separately using space between them." << endl;
    //string firstName, lastName;
    cin >> firstName >> lastName;

    double howManyClass;

    cout << "Enter how many classes you took last semester." << endl;
    //double howManyClass;
    cin >> howManyClass;

    double gpa = 0;
    double credits;
    double totalcredits = 0;

    for (int i = 1; i <= howManyClass; i++)
    {
        string Class;
        int ClassNumber;

        cout << "Enter 4 letters and 4 numbers of your class you took last semester using space between them." << endl;
        /*string Class;
        int ClassNumber;*/
        cin >> Class >> ClassNumber;

        cout << "Enter the credits of your class which you entered." << endl;
        /*double credits;*/
        cin >> credits;

        char grade;

        cout << "Enter a letter of your class grade you got.ex)A, B, C, D, E, or F" << endl;
        cin >> grade;

        if (toupper(grade)== 'A')
        {
            cout << "Your class grade of " << Class << ClassNumber << " is 4.0." << endl;
            gpa += (credits * 4.0);
            totalcredits += credits;
         }
        else if (toupper(grade) == 'B')
        {
            cout << "Your class grade of " << Class << ClassNumber << " is 3.0." << endl;
            gpa += (credits * 3.0);
            totalcredits += credits;
        }
        else if (toupper(grade) == 'C')
        {
            cout << "Your class grade of " << Class << ClassNumber << " is 2.0." << endl;
            gpa += (credits * 2.0);
            totalcredits += credits;
        }
        else if (toupper(grade) == 'D')
        {
            cout << "Your class grade of " << Class << ClassNumber << " is 1.0." << endl;
            gpa += (credits * 1.0);
            totalcredits += credits;
        }
        else if (toupper(grade) == 'E')
        {
            cout << "Your class grade of " << Class << ClassNumber << " is 0.0." << endl;
            gpa += (credits * 0.0);
            totalcredits += credits;
        }
        else if (toupper(grade) == 'F')
        {
            cout << "Your class grade of " << Class << ClassNumber << " is fail." << endl;
            gpa += (credits * 0.0);
            totalcredits += credits;
        }
        else {
            cout << "Enter designed lettter." << endl;
            return 0;

        }
 
    }
    cout << "\n" << firstName << " " << lastName << "  GPA " << gpa / totalcredits << "\n" << "Detail" << "\n" << "Total credit in this term: " << totalcredits << "\n" << "Total credits * grades " << gpa << endl;
    return 0;
}




