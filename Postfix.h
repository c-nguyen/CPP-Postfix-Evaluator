/*
 * Postfix.h
 *
 *  Created on: Apr 9, 2015
 *      Author: Christine
 */

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
