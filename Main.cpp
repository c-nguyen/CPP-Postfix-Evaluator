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
	Postfix calculator;
	string equation;

	cout << "Enter an expression in Postfix notation: ";
	getline(cin, equation);

	cout << "equation is " << equation;

	calculator.setEquation(equation);
	cout << "The answer is " << calculator.evaluate() << ".";

	return 0;
}
