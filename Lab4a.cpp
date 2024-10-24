#include <iostream>

using namespace std;

int main()
{
	double price1 = 50.35;
	double price2 = 80.28;
	double price3 = 38.51;
	double number1, number2, number3; 


	cout << "The price of product1 is $50.35." << "\n" << "The price of product2 is $80.28." << "\n" << "The price of product1 is $38.51." << endl;
	cout << "How many do you want to buy each product? Enter number how many products you want to buy each using space between them." << endl;
	cin >> number1 >> number2 >> number3;

	double priceTotal = price1 * number1 + price2 * number2 + price3 * number3;
	if (priceTotal <= 200.00) {
		priceTotal += 9.99;
	}
	else if (priceTotal >= 200.00 && priceTotal <= 500.00) {
		cout << "No shipping charges since the purchase is over 200." << endl;
	}
	else {
		cout << "Since the purchase is higher than $500, a 10% discount is applied." << endl;
		priceTotal = priceTotal * 0.9;
	}
	cout << "Finally, your total cost is " << totalCost << "." << endl;
	
	return 0;
}
