/******************************************************************************
 * Name        : Postfix.h
 * Author      : Christine Nguyen
 * Description : This program evaluates expressions in Postfix notation.
 *               The program has a class to store the expression and the
 *               calculated result. The class also has an Eval function that
 *               parses the input expression and calculate the result.
 *****************************************************************************/

#ifndef POSTFIX_H_
#define POSTFIX_H_

#include <iostream>
#include <string>  // For strings
#include <stack>   // For stack functions
#include <cctype>  // For character manipulation
#include <cstdlib> // For atoi function

using namespace std;

class Postfix {
    public:
        void setEquation(string eq);
        bool checkError();
        double evaluate();
        
    private:
        string equation;
};

#endif /* POSTFIX_H_ */
