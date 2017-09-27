/*Yemane Zewdu
Data Structures: RPN converter in C++
09/25/2017
*/

#include<iostream>
#include<string>
#include<stack>
#include<sstream>
using namespace std;

bool isOperator(string &userInput)
{
	string OperArray[] = { "+", "-", "*","/" };

	for (int i = 0; i < 4; i++) {
		if (userInput == OperArray[i]) {
			return true;
		}
	}
	return false;
}

void performOp(string &Input, stack<double> &stack)
{
	double leftOprnd, rightOprnd, result;

	rightOprnd = stack.top();
	stack.pop();

	leftOprnd = stack.top();
	stack.pop();
	if (Input == "+") {
		result = leftOprnd + rightOprnd;
	}
	else if (Input == "-") {
		result = leftOprnd - rightOprnd;
	}
	else if (Input == "*") {
		result = leftOprnd * rightOprnd;
	}
	else if (Input == "/") {
		if (rightOprnd != 0) {
			result = leftOprnd / rightOprnd;
		}
		else {
			cout << "Can't divide by 0!\n";
		}
	}
	cout <<"The result is: " << result << endl;
	stack.push(result);
}

int main() {
	stack<double> calcStack;
	string input;
	double num;
	cout << "This is a RPN converter Program!\n\n"
		<< "press 'Q' anytime you want to quit\n";

	while (true) {
		// displaying a prompt 
		cout << "Enter any operand or operator: \n";
		cin >> input;
		// checking if the input is an operand
		if (istringstream(input) >> num)
		{
			calcStack.push(num);
		}
		else if (isOperator(input))
		{
			performOp(input, calcStack);
		}
		else if (input == "q" || "Q")
		{
			cout << "Good Bye!!\n";
			return 0;
		}
		else {
			cout << "Invalid Input!\n";
		}
	}
	system("pause");
}
