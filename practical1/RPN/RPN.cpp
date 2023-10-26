#include "RPN.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;



void printStack(vector<string>& stack) {
    cout << "[";
    for(int i = 0; i < stack.size(); i++){
        cout << stack[i];
        if(i < stack.size() - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}



void clearStack(vector<string>& stack) {
    stack.clear();
}



bool isOperator(string token) {
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "sin" || token == "cos";
}



int evaluate(string op, int a, int b) {
    if(op == "+"){
        return a + b;
    }
    else if(op == "-"){
        return a - b;
    }
    else if(op == "*"){
        return a * b;
    }
    else if(op == "/"){
        return a / b;
    }
    else if(op == "^"){
        return pow(a, b);
    }
    else if(op == "sin"){
        return sin(a);
    }
    else if(op == "cos"){
        return cos(a);
    }
    else{
        cout <<"Unknown operator: ";
    }
}



void printResult(int result) {
    cout << "Result: " << result << endl;
}



string convertToRPN(vector<string>& tokens) {
    vector<string> stack;
    vector<string> output;

    map<string, int> precedence;
    precedence["sin"] = 4;
    precedence["cos"] = 4;
    precedence["^"] = 3;
    precedence["*"] = 2;
    precedence["/"] = 2;
    precedence["+"] = 1;
    precedence["-"] = 1;

    for(int i = 0; i < tokens.size(); i++){
        string token = tokens[i];

        if(isdigit(token[0]) || (token[0] == '-' && token.length() > 1)){
            output.push_back(token);
            cout << "Output: ";
            printStack(output);
        }
        else if(isOperator(token)){
            while(!stack.empty() && isOperator(stack.back()) && precedence[token] <= precedence[stack.back()]){
                string op = stack.back();
                stack.pop_back();
                output.push_back(op);
                cout << "Output: ";
                printStack(output);
            }
            stack.push_back(token);
            cout << "Stack: ";
            printStack(stack);
        }
        else if(token == "("){
            stack.push_back(token);
            cout << "Stack: ";
            printStack(stack);
        }
        else if(token == ")"){
            while(!stack.empty() && stack.back() != "("){
                string op = stack.back();
                stack.pop_back();
                output.push_back(op);
                cout << "Output: ";
                printStack(output);
            }
            if(stack.empty() || stack.back() != "("){
                cout << "Error" << endl;
            }
            stack.pop_back();
            cout << "Stack: ";
            printStack(stack);
        }
        else{
            cout << "Unknown token" << endl;
        }
    }
    while(!stack.empty()){
        string op = stack.back();
        stack.pop_back();
        if(op == "("){
            cout << "Error" << endl;
        }
        output.push_back(op);
        cout << "Output: ";
        printStack(output);
    }
    tokens = output;
    return output.back();
}



double evaluateExpressionToRPN(vector<string>& tokens) {
    vector<string> stack;
    double result;

    for(int i = 0; i < tokens.size(); i++){
        string token = tokens[i];
        if(isOperator(token)){
            if(token == "sin" || token == "cos"){
                if(stack.size() < 1){
                    cout << "Error: Not enough operands for " << endl;
                }
                double arg = stod(stack.back());
                stack.pop_back();
                double functionResult;
                if(token == "sin"){
                    functionResult = sin(arg * 3.14 / 180);
                }
                else if(token == "cos"){
                    functionResult = cos(arg * 3.14 / 180);
                }
                stack.push_back(to_string(functionResult));
            }
            else{
                if(stack.size() < 2){
                    cout << "Error: Not enough operands for operator " << endl;
                }
                double b = stod(stack.back());
                stack.pop_back();
                double a = stod(stack.back());
                stack.pop_back();
                result = evaluate(token, a, b);
                stack.push_back(to_string(result));
            }
            cout << "Stack after evaluating " << token << ": ";
            printStack(stack);
            printResult(result);
        }
        else{
            stack.push_back(token);
            cout << "Stack after pushing " << token << ": ";
            printStack(stack);
        }
    }
    if(stack.size() != 1){
        cout << "Error: Invalid expression" << endl;
    }
    return stod(stack.back());
}