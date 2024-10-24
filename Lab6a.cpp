#include <iostream>

using namespace std;

double larger2(double a, double b);
double largest7(double a, double b, double c, double d, double e, double f, double g);

int main()
{
    cout << "Enter seven numbers" << endl;
    double num1, num2, num3, num4, num5, num6, num7;
    cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7;
    double number = largest7(num1, num2, num3, num4, num5, num6, num7);
    cout << "The larger number: " << number << endl;
    return 0;
}

double larger2(double a, double b)
{
    if (a >= b)
        return a;
    else
        return b;
}
double largest7(double a, double b, double c, double d, double e, double f, double g)
{
    return larger2(larger2(larger2(a, b), larger2(c, d)),larger2(larger2(e,f),g));
}

