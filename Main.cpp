/******************************************************************************
 * Name        : main.cpp
 * Author      : Christine Nguyen
 * Description : This program evaluates expressions in Postfix notation.
 *               The program has a class to store the expression and the
 *               calculated result. The class also has an Eval function that
 *               parses the input expression and calculate the result.
 *****************************************************************************/
#include "Postfix.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Define an instance of the class
	Postfix calculator;
	// equation = user input equation
	string equation;
	// isOkay = is equation valid
	bool isOkay = false;

	// While equation is not valid, keep asking for input
	while (!isOkay) {
		// Prompt user to enter an equation
		cout << "\nEnter an expression in Postfix notation: ";
		// Get the entire line
		getline(cin, equation);

		// Set the equation in the class
		calculator.setEquation(equation);

		// If there are no errors
		if (calculator.checkError() == true) {
			// Calculate the answer
			double answer = calculator.evaluate();
			// If answer is null, equation is not valid
			if (!answer)
				cout << "You have entered an invalid expression. Try Again." << endl;
			// Else, print out answer and end loop
			else {
				cout << "The answer is " << answer << ".";
				isOkay = true;
			}
		// Else (there are errors), go to beginning of loop
		} else
			cout << "You have entered an invalid expression. Try Again." << endl;
	}
	return 0;
}
