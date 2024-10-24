#include <forward_list>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int main() {
	forward_list<int> numbers;
	numbers.push_front(1);
	numbers.push_front(2);
	numbers.push_front(3);
	int number = numbers.front();
	numbers.pop_front();

	queue<int> numberQueue;
	numberQueue.push(4);
	numberQueue.push(5);
	numberQueue.push(6);
	int frontElement = numberQueue.front();
	numberQueue.pop();
	bool isQueueEmpty = numberQueue.empty();

	stack<int> numberStack;
	numberStack.push(7);
	numberStack.push(8);
	numberStack.push(9);
	int topElement = numberStack.top();
	numberStack.pop();
	bool isStackEmpty = numberStack.empty();

	cout << "Forward List: ";
	for (int element : numbers) {
		cout << element << " ";
	}

	cout << "\nQueue Front Element: " << frontElement << endl;
	cout << "Is Queue Empty? " << (isQueueEmpty ? "Yes" : "No") << endl;

	cout << "\nStack top Element: " << topElement << endl;
	cout << "Is Stack Empty? " << (isStackEmpty ? "Yes" : "No") << endl;

	return 0;
}