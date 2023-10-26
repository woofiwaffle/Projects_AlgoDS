#include "Stack.h"
#include <iostream>

using namespace std;



void Stack::push(int value) {
    elements.push_back(value);
}



void Stack::pop() {
    if(!isEmpty()){
        elements.pop_back();
    }
    else{
        cout << "Stack is empty" << endl;
    }
}



int Stack::top() const {
    if(!isEmpty()){
        return elements.back();
    }
    else{
        cout << "Stack is empty. No top element" << endl;
        return -1;
    }
}



bool Stack::isEmpty() const {
    return elements.empty();
}



void Stack::printStack() const {
    if(!isEmpty()){
        cout << "Stack elements: ";
        for(int element: elements){
            cout << element << " ";
        }
        cout << endl;
    }
    else{
        cout << "Stack is empty" << endl;
    }
}



int Stack::sizeStack() const{
    return elements.size();
}



int Stack::kStack() {

    Stack stack;

    int choice, value;

    while (true) {

        cout << "--------------------------------------------" << endl;
        cout << "|Choose an option:\n";
        cout << "|1. Push element onto the stack\n";
        cout << "|2. Pop element from the stack\n";
        cout << "|3. View the top element of the stack\n";
        cout << "|4. Print stack\n";
        cout << "|5. Get the size of the stack\n";
        cout << "|0. Exit\n";
        cout << ">> ";
        cin >> choice;
        cout << "--------------------------------------------" << endl;

        switch(choice){
            case 1: {
                cout << "Enter the value to push onto the stack: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 2: {
                stack.pop();
                break;
            }
            case 3: {
                int topValue = stack.top();
                if(topValue != -1){
                    cout << "Top element: " << topValue << endl;
                }
                break;
            }
            case 4: {
                stack.printStack();
                break;
            }
            case 5:{
                cout << "Size of the stack: " << stack.sizeStack() << endl;
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
}
