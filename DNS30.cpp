#include <iostream>

using namespace std;

int main()
{
    int num = 1;
    int i = 1;
    int x1, x2;
    int x3 = 0;
    cout << "Choose first attack or second attack. If you want to attak first, type f. If you want to attack second, type s." << endl;
    char order;
    cin >> order;
    //Patern first attack
    if (toupper(order) == 'F') {
        cout << "Enter 3 numbers from 1 using space between them. First choice is going to be one of these 0 0 1, 0 1 2, 1 2 3" << endl;
        for (i = 1; x3 < 29; i++) {
            cin >> x1 >> x2 >> x3;
            if (x3 == 29) {
                cout << 0 << " " << 0 << " " << 30 << "\n" << "Congraturations. You win." << endl;
                return 0;
            }
            else if  (x3 % 4 == 0) {
                cout << 0 << " " << 0 << " " << x3 + 1 << endl;
                x3 += 1;
            }
            else if (x3 % 4 == 1) {
                cout << 0 << " " << 0 << " " << x3 + 1 << endl;
                x3 += 1;
            }
            else if (x3 % 4 == 2) {
                cout << x3 + 1 << " " << x3 + 2 << " " << x3 + 3 << endl;
                x3 += 3;
            }
            else if (x3 % 4 == 3) {
                cout << 0 << " " << x3 + 1 << " " << x3 + 2 << endl;
                x3 += 2;
            }
            else {
                cout << "Enter the proper numbers." << endl;
                return 0;
            }
        }
        cout << "Enter 30." << endl;
        cin >> x3;
        if (x3 == 30) {
            cout << "You lose either way." << "\n" << "Thank you for your losing for me." << endl;
        }
        else {
            cout << "You lose either way." << "\n" << "Thank you for your losing for me." << endl;
        }
    }

    //Patern second attack
    else if (toupper(order) == 'S') {
        cout << 0 << " " << 0 << " " << num << endl;
        for (i = 1; num < 29; i++) {
            cin >> x1 >> x2 >> x3;
            if (x3 == num + 1) {
                cout << x3 + 1 << " " << x3 + 2 << " " << x3 + 3 << endl;
                num += 4;
            }
            else if (x3 == num + 2) {
                cout << 0 << " " << x3 + 1 << " " << x3 + 2 << endl;
                num += 4;
            }
            else if (x3 == num + 3) {
                cout << 0 << " " << 0 << " " << x3 + 1 << endl;
                num += 4;
            }
            else {
                cout << "Enter the proper numbers." << endl;
                return 0;
            }
        }
        cout << "Enter 30." << endl;
        cin >> num;
        if (num == 30) {
            cout << "You lose." << "\n" << "Thank you for your losing for me." << endl;
        }
        else {
            cout << "You lose either way." << "\n" << "Thank you for your losing for me." << endl;
        }
    }
    else {
        cout << "Enter proper character next time." << endl;

    }
    return 0;
}
