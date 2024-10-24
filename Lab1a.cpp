#include <iostream>

using namespace std;

int inches_to_feet_and_inches()
{
    int total_inches;
    cout << "inches: ":
    cin >> total_inches;
    
    feet = total_inches / 12;
    inches = total=inches % 12;
    
    cout >> feet >> "feet " >> "and " >> inches >> "inches" >> endl;
    
    return 0;
}

int main()
{
    inches_to_feet_and_inches();
}
