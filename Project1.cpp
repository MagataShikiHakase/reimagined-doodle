#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Name {
public:
    string first_name;
    string last_name;
};

class Birthday {
public:
    string day;
    string month;
    string year;
};

class Profession {
public:
    string profession;
};

class Hobbies {
public:
    string hobbies;
};

class Person : public Name, public Birthday, public Profession, public Hobbies {
};

class PersonInfo : public Person {
public:
    string relation;
    void set_person_info()  {
        cout << "Enter first name: ";
        cin >> first_name;
        cout << "Enter last name: ";
        cin >> last_name;
        cout << "Enter date of birth (MM/DD/YYYY): ";
        cin >> month >> day >> year;
        cout << "Enter profession: ";
        cin >> profession;
        cout << "Enter hobbies: ";
        cin >> hobbies;
        cout << "Enter relation: ";
        cin >> relation;
    }
    void show_person_info()  {
        cout << "Name: " << first_name << " " << last_name << endl;
        cout << "Date of Birth: " << month << "/" << day << "/" << year << endl;
        cout << "Profession: " << profession << endl;
        cout << "Hobbies: " << hobbies << endl;
        cout << "Relation: " << relation << endl << endl;
    }
};

int main() {
    int num_persons;
    cout << "Enter the number of persons: ";
    cin >> num_persons;

    vector<PersonInfo> persons(num_persons);

    for (int i = 0; i < num_persons; i++) {
        cout << "Enter details for Person " << i + 1 << endl;
        persons[i].set_person_info();
        cout << endl;
    }

    string search_person_info;

    while (true) {
        cout << "Enter person info to search: (Enter Q, if you want to quit this program) ";
        cin >> search_person_info;
        cout << endl;

        if (search_person_info == "Q" or search_person_info == "q")
        {
            break;
        }

        for (int i = 0; i < num_persons; i++) {
            if (persons[i].first_name == search_person_info || persons[i].last_name == search_person_info ||
                persons[i].profession == search_person_info || persons[i].hobbies == search_person_info ||
                persons[i].relation == search_person_info ||
                (persons[i].month + "/" + persons[i].day + "/" + persons[i].year) == search_person_info ||
                (persons[i].month + " " + persons[i].day + " " + persons[i].year) == search_person_info ||
                persons[i].month == search_person_info || persons[i].day == search_person_info || persons[i].year == search_person_info) {
                persons[i].show_person_info();
            }
        }
    }

    return 0;
}