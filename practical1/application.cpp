#include "application.h"
#include "Structures/DL_List.h"
#include "Structures/D_Array.h"
#include "Structures/Stack.h"
#include "RPN/RPN.h"

#include <iostream>
#include <sstream>

using namespace std;



int application::exec() {

    char ch;
    bool exit = false;
    while(!exit){
        ch = menu();
        switch(ch){
            case '1':{
                DL_List();
                break;
            }
            case '2':{
                DynamicArray::D_Array();
                break;
            }
            case '3':{
                Stack::kStack();
                break;
            }
            case '4': {
                string s;
                vector<string> tokens;
                string token;
                string input;

                cout << "Enter expression: ";
                getline(cin, input);
                cout << "You entered: " << input << endl;

                stringstream ss(input);
                while (ss >> token) {
                    tokens.push_back(token);
                }

                cout << "Original expression: ";
                printStack(tokens);
                convertToRPN(tokens);
                cout << "Expression in RPN: ";
                printStack(tokens);
                cout << endl;

                double result = evaluateExpressionToRPN(tokens);
                cout << "Final result: " << result << endl;

                clearStack(tokens);
                cout << "\n\n";
                break;
            }
            case '0':{
                cout << "Exit" << endl;
                exit = true;
                break;
            }
            default:{
                cout << "Error\n";
                break;
            }
        }
    }
}



int application::menu(){
    char ch;
    cout << "--------------------------------------------" << endl;
    cout << "|Choose the method" << endl;
    cout << "|1 - Doubly Linked List" << endl;
    cout << "|2 - Dynamic Array" << endl;
    cout << "|3 - Stack" << endl;
    cout << "|4 - Reverse Polish Notation" << endl;
    cout << "|0 - Exit" << endl << "> ";
    cin >> ch;
    cin.ignore();
    cout << "--------------------------------------------" << endl;
    return ch;
}
