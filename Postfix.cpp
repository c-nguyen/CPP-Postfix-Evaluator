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
// Constructor                                                                *
//*****************************************************************************
Postfix::Postfix()
{
    //ctor
}

//*****************************************************************************
// Destructor                                                                 *
//*****************************************************************************
Postfix::~Postfix()
{
    //dtor
}

//*****************************************************************************
// setEquation assigns the string parameter to the global variable (equation).*
//*****************************************************************************
void Postfix::setEquation(string eq) {
    equation = eq;
}

//*****************************************************************************
// evaluate goes through the whole equation and calculates the answer using a *
// stack.                                                                     *
//*****************************************************************************
double Postfix::evaluate() {
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
        }
        // If cursor is an operation - pop 2 numbers off stack and do
        // the operation specified
        else {
            double answer;
            double first = operands.top();
            operands.pop();
            double second = operands.top();
            operands.pop();

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
        }
    }
    // Store the calculated answer
    answer = operands.top();
    // Return the answer
    return answer;
}
