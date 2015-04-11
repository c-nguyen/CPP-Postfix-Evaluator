/******************************************************************************
 * Name        : Postfix.h
 * Author      : Christine Nguyen
 * Description : This program evaluates expressions in Postfix notation.
 *               The program has a class to store the expression and the
 *               calculated result. The class also has an Eval function that
 *               parses the input expression and calculate the result.
 *****************************************************************************/

#ifndef SRC_POSTFIX_H_
#define SRC_POSTFIX_H_

#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Postfix {
    public:
        string equation;
        stack<int> operands;
        Postfix();
        virtual ~Postfix();
        void setEquation(string eq);
        double evaluate();
};

#endif /* SRC_POSTFIX_H_ */
