//============================================================================
// Name        : CS.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

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
