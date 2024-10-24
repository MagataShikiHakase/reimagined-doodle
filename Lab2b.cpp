#include <iostream>

using namespace std;

int main() {
  int day_of_solstice = 121;
  int day_of_week = day_of_solstice % 7;

  cout << "The winter solstice is " << day_of_week << endl;
  cout << "0 means Monday, 1 means Tuesday, 2 means Wednesday, 3 means "
          "Thursday, 4 means Friday, 5 means Saturaday, 6 means Sunday"
       << endl;
  return 0;
}

// 0 wed
/*
1 thur
2 fri
3 sat
*/
