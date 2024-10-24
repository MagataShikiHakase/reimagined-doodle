#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	char arithmeticOperator;
	cout << "What caluculation do you want to do?" << endl;
	cin >> num1 >> arithmeticOperator >> num2;

	switch (arithmeticOperator) {
	case '+':
			cout << num1 << arithmeticOperator << num2 << "=" << num1 + num2 << endl;
			break;
	case '-':
		    cout << num1 << arithmeticOperator << num2 << "=" << num1 - num2 << endl; 
			break;
	case '%':
			cout << num1 << arithmeticOperator << num2 << "=" << num1 % num2 << endl; 
			break;
	case '*':
			cout << num1 << arithmeticOperator << num2 << "=" << num1 * num2 << endl; 
			break;
	case '/':
			cout << num1 << arithmeticOperator << num2 << "=" << num1 / num2 << endl;
			break;
	default:
		cout << "This program can't handle the caluculation you entered." << endl;
		break;
	}
	return 0;
}