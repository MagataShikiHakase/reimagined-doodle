#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, D, x1, x2;
	cin >> a >> b >> c;
	D = sqrt(pow(b, 2) - 4*a*c);

	assert(a != 0);

	if (D > 0) {
		x1 = (-b + D) / 2 * a;
		x2 = (-b - D) / 2 * a;
		cout << "Discriminant is more than 0." << "\n" << "The answers are x =" << x1 << ", " << x2 << endl;
	}
	else if (D == 0) {
		x1 = -b / 2 * a;
		cout << "Discriminant is the exact 0." << "\n" << "The answer is x =" << x1 << endl;
	}
	else {
		cout << "Discriminant is less than 0. There are zero solutions for real numbers and imaginary solutions." << endl;
	}
	return 0;
}