#include <iostream>
#include <cmath>

using namespace std;

bool isValidNumber(int a);

void primeFactorization(int a, int counter);

int bigger(int a, int b);

int smaller(int a, int b);

int greatestCommonDivisorValue(int a, int b);

void greatestCommonDivisorPrint(int a, int b); //euclidean algorithm

void leastCommonMultiple(int a, int b);


int main()
{
	int whatYouWantToKnow = 0, num1, num2, counter = 0;
	bool check = isValidNumber(whatYouWantToKnow);
	cout << "Enter 1, if you want to know the number's prime factor decomposition." << endl;
	cout << "Enter 2, if you want to know the greatest common divisor and least common multiple of TWO numbers." << endl;
	cout << "Enter 3, if you want to know the convergence of Pi." << endl;

	do
	{
		cin >> whatYouWantToKnow;
		check = isValidNumber(whatYouWantToKnow);
	} while (check != true);

	if (whatYouWantToKnow == 1)
	{
		cout << "Enter a single number that you want to decomposite to prime numbers. ";
		cin >> num1;
		cout << endl;
		primeFactorization(num1, counter);
		return 0;
	}

	else if (whatYouWantToKnow == 2)
	{
		cout << "Enter two numbers that you want to know the greatest common divisor and least common multiple. " << endl;
		cin >> num1 >> num2;
		cout << endl;
		greatestCommonDivisorPrint(num1, num2);
		leastCommonMultiple(num1, num2);
		return 0;
	}

	else if (whatYouWantToKnow == 3)
	{
		double n, internalangle, externalangle, internaledge, totalinternaledge, totalexternaledge, const PI = 3.1415926;
		cout << "Enter the integer which is equal to 3 or more than 3" << endl;
		cout << "Narrow down the circumference of circle from the lengths of the sides of the regular n-angle inscribed in th the circle and the regular n-angle circumscribed by the circle." << endl;
		cout << "keep entering the number n:" << endl;
		while (true)
		{
			cin >> n;
			internalangle = 2 * PI / n;
			externalangle = (PI * (n - 2)) / n;

			internaledge = sqrt(2 - 2 * cos(internalangle));
			totalinternaledge = n * sqrt(2 - 2 * cos(internalangle));
			totalexternaledge = 2 * n * (internaledge * sin((PI - externalangle) / 2) / sin(externalangle));

			cout << totalinternaledge/2 << " < PI < " << totalexternaledge/2 << endl;
		}
	}
}
bool isValidNumber(int a)
{
	if (a >= 1 and a <= 3)
		return true;
	else
		return false;
}

void primeFactorization(int a, int counter)
{
	int repetition = 0;
	cout << a << " = ";
	for (int i = 2; i <= pow(2, 31); i++)
	{
		repetition = 0;
		while (true)
		{
			if (a % i != 0)
				break;
			a /= i;
			repetition++;
		}
		if (repetition == 0)
			continue;
		cout << "(" << i << " ^ " << repetition << ")";
		counter++;
		if (a == 1)
			break;
	}
	cout << endl;
	if (counter == 1 && repetition == 1)
		cout << "This number is prime." << endl;
}

int bigger(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int smaller(int a, int b)
{
	if (bigger(a, b) == a)
		return b;
	else if (bigger(a, b) != a)
		return a;
}

int greatestCommonDivisorValue(int a, int b)
{
	int x, y, z, w;

	x = bigger(a, b), y = smaller(a, b);
	while (true)
	{
		z = x / y;
		w = x - y * z;
		if (w == 0)
			break;
		x = y;
		y = w;
	}
	return y;
}

void greatestCommonDivisorPrint(int a, int b) //euclidean algorithm
{
	cout << "The greatest common divisor: " << greatestCommonDivisorValue(a, b) << endl;
}

void leastCommonMultiple(int a, int b)
{
	int leastCommonMultipleNum, greatestCommonDivisor = greatestCommonDivisorValue(a, b);
	leastCommonMultipleNum = a * b / greatestCommonDivisor;
	cout << "The least common multiple: " << leastCommonMultipleNum << endl;
}
