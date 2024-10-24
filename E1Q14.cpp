#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i = 1, a, b, c, n;
	while (true)
	{
		cout << "Loop iteration number " << i << endl;
		cout << "Enter coefficients a, b, c and an exponent n:" << endl;
		cin >> a;
		cin >> b;
		cin >> c;
		cin >> n;
		cout << "Function is:" << "\n" << a << " (x ^ " << n << ") + " << b << " (x ^ " << n - 1 << ") + " << c << " (x ^ " << n - 2 << ")" << endl << endl;
		cout << "Derivative is:" << "\n" << a * n << " (x ^ " << n - 1 << ") + " << b * (n - 1) << " (x ^ " << n - 2 << ") + " << c * (n - 2) << " (x ^ " << n - 3 << ")" << endl << endl;
		cout << "-----------------------------" << endl;
		i++;
	}

	return 0;
}