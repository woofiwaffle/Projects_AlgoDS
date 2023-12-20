#include "application.h"
#include "KruskalsAlgorithm/KruskalsAlgorithm.h"

#include <iostream>

using namespace std;


int application::exec() {

    char ch;
    bool exit = false;
    while(!exit){
        ch = menu();
        switch(ch){
            case '1':{
                KruskalsAlgorithm KruskalsAlgorithm("C:\\Users\\User\\CLionProjects\\Projects_AlgoDS\\coursework\\KruskalsAlgorithm\\inputgraph.txt",
                                                    "C:\\Users\\User\\CLionProjects\\Projects_AlgoDS\\coursework\\KruskalsAlgorithm\\outputMST.txt");
                KruskalsAlgorithm.sortEdges();
                KruskalsAlgorithm.kruskal();
                KruskalsAlgorithm.outputInFile();
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
    cout << "-----------------------\n";
    cout << "| Kruskal`s algorithm |\n";
    cout << "-----------------------\n";
    cout << "|Choose the method" << endl;
    cout << "|1 - Enter graph from file" << endl;
    cout << "|0 - Exit" << endl << "> ";
    cin >> ch;
    cin.ignore();
    cout << "--------------------------------------------" << endl;
    return ch;
}
