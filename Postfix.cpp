/******************************************************************************
 * Name        : Postfix.cpp
 * Author      : Christine Nguyen
 * Description : This program evaluates expressions in Postfix notation.
 *               The program has a class to store the expression and the
 *               calculated result. The class also has an Eval function that
 *               parses the input expression and calculate the result.
 *****************************************************************************/
#include "Postfix.h"

//*****************************************************************************
// checkError checks if there is a syntax error in the user's input (equation)*
// by checking the last character in the equation. The last character should  *
// be an operand. If it is an operand, then the function returns true, else   *
// it returns false.                                                          *
//*****************************************************************************
bool Postfix::checkError() {
	// Check for syntax errors in user input
	// Last character in equation must be an operation
	return (equation[equation.length() - 1] == '+' ||
		equation[equation.length() - 1] == '-' ||
		equation[equation.length() - 1] == '*' ||
		equation[equation.length() - 1] == '/') ? true: false;
}

//*****************************************************************************
// evaluate goes through the whole equation and calculates the answer using a *
// stack.                                                                     *
//*****************************************************************************
double Postfix::evaluate() {
	try {
		// Declare stack to hold numbers
		stack<double> operands;
		// i = index of string
		int i = 0;
		// While the end of the string has not been reached
		while (equation[i] != '\0') {
			// cursor = current character of string
			char cursor = equation[i];
			// If cursor is a space - move to next character
			if (isspace(cursor)) {
				i++;
			}
			// If cursor is a number - convert to double and push onto stack
			else if (isdigit(cursor)) {
				string number = "";
				while (!isspace(cursor)) {
					number += cursor;
					i++;
					cursor = equation[i];
				}
				operands.push(atof(number.c_str()));
				i++;
			// Else if cursor is an operation
			} else if (cursor == '+' || cursor == '-' || cursor == '*' ||
					cursor == '/') {
				// If there is a problem with the input equation
				// Return a nullptr
				if (operands.size() < 2)
					return NULL;

				// Else do the operations
				// Pop off top 2 numbers from stack
				double answer;
				double first = operands.top();
				operands.pop();
				double second = operands.top();
				operands.pop();

				// Determine and execute operation
				switch(cursor) {
					case '+':
						answer = second + first;
						break;
					case '-':
						answer = second - first;
						break;
					case '*':
						answer = second * first;
						break;
					case '/':
						answer = second / first;
						break;
				}
				// Push the answer onto the stack
				operands.push(answer);
				i++;
			// Else if cursor is not a space, digit, or operand
			} else {
				i++;
			}
		}
		// Return the answer
		return operands.top();
	// Catch any unforeseen exceptions
	} catch (...) {
		return NULL;
	}
}
