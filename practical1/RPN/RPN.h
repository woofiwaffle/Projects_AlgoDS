#ifndef PROJECTS_ALGODS_RPN_H
#define PROJECTS_ALGODS_RPN_H

#ifndef PRACTICAL1_RPN_H
#define PRACTICAL1_RPN_H

#include <vector>
#include <string>
#include <iostream>


void printStack(std::vector<std::string>& stack);
void clearStack(std::vector<std::string>& stack);
bool isOperator(std::string token);
int evaluate(std::string op, int a, int b);
void printResult(int result);
std::string convertToRPN(std::vector<std::string>& tokens);
double evaluateExpressionToRPN(std::vector<std::string>& tokens);

#endif //PRACTICAL1_RPN_H


#endif //PROJECTS_ALGODS_RPN_H
