#include "application.h"


#include <iostream>

using namespace std;



int application::exec() {


    char ch;
    bool exit = false;
    while(!exit){
        ch = menu();
        switch(ch){
            case '1': {

                break;
            }
            case '2': {

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
    cout << "|1 - Create a binary tree" << endl;
    cout << "|2 - Create a AVL tree" << endl;
    cout << "|3 - Algorithm for parsing bracket notation" << endl;
    cout << "|0 - Exit" << endl << "> ";
    cin >> ch;
    cin.ignore();
    cout << "--------------------------------------------" << endl;
    return ch;
}
