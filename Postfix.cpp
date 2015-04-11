#include "Postfix.h"

Postfix::Postfix()
{
    //ctor
}

Postfix::~Postfix()
{
    //dtor
}

void Postfix::setEquation(string eq) {
    equation = eq;
}

double Postfix::evaluate() {
    int i = 0;
    while (equation[i] != '\0') {
        char cursor = equation[i];
        if (isspace(cursor))
            i++;
        else if (isdigit(cursor))
            operands.push(cursor);
        else {
            int answer;
            int first = operands.pop();
            int second = operands.pop();

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
            operands.push(answer);
        }
        i++;
    }
    return operands.pop();
}
