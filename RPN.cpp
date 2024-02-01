//
// Created by Nu lar on 11/14/23.
//
#include "RPN.h"

double RPN::evaluate(double left, double right, char op)
{
    switch (op)
    {
        case '+':
            //std::cout<<"left: "<<left<<std::endl;
            //std::cout<<"right: "<<right<<std::endl;
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left/right;
        case '^':
            return pow(left,right);
        default :
            return -1;
    }
}

double RPN::evaluate(const std::string& Expression) {
    std::stack<double> stack;
    for (int i = 0; i < Expression.size(); i++) {
        if (isOperator(Expression[i]) && (Expression[i] != '='))
        {
            //std::cout<<"stack size: "<<stack.size()<<std::endl;
            while(stack.size()>1) {
                double right = stack.top();
                //std::cout << right << std::endl;
                stack.pop();
                double left = stack.top();
                //std::cout << left << std::endl;
                stack.pop();
                stack.push(evaluate(left, right, Expression[i]));
            }
        }
        else if(isOperand(Expression[i]))
        {
            stack.push(Expression[i] - 48);   ///ASCII synchronize
        }
    }
    return stack.top();
}

bool RPN::isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch=='/' || ch=='^');
}

bool RPN::isOperand(char ch)
{
    return (ch >= '0' && ch <= '9');
}
