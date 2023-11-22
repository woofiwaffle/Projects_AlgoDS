#include "application.h"
#include "Trees/BinaryTree.h"
#include "Trees/AVLTree.h"



int application::exec() {

    BinaryTree binaryTree;
    AVLTree avlTree;

    char ch;
    bool exit = false;
    while(!exit){
        ch = menu1();

        switch(ch){
            case '1': {
                string expression;
                cout << "Enter expression tree: " << endl;
                getline(cin, expression);

                cout << "\n" << endl;

                binaryTree.parseTree(expression);

                cout << "Binary tree: \n" << endl;
                binaryTree.printBinaryTree();
                cout << "\n------------------------------------------------------------------------------------\n";
                break;
            }
            case '2' : {
                binaryTree.createBinaryTreeFromFile(R"(C:\Users\User\CLionProjects\Projects_AlgoDS\practical3\Trees\outputBinaryTree.txt)");

                cout << "Binary tree: \n" << endl;
                binaryTree.printBinaryTree();
                cout << "\n------------------------------------------------------------------------------------\n";
                break;
            }
            case '3' : {
                cout << "Direct bypass: \n";
                binaryTree.bypassDirect();
                cout << "\n------------------------------------------------------------------------------------\n";
                vector<int> arrayNum;
                binaryTree.array(binaryTree.getRoot(), arrayNum);
                for(int number : arrayNum){
                    avlTree.insert(number);
                }

                cout << "AVL tree: \n" << endl;
                avlTree.printAVLTree();
                cout << "\n------------------------------------------------------------------------------------\n";
                break;
            }
            case '4' : {
                char c;
                bool ex = false;
                while(!ex){
                    c = menu2();

                    switch(c){
                        case '1': {
                            int value;
                            cout << "Enter a value to insert: ";
                            cin >> value;
                            avlTree.insert(value);

                            cout << "AVL tree: \n" << endl;
                            avlTree.printAVLTree();
                            cout << "\n-----------------------------------------------------------------------------\n";
                            break;
                        }
                        case '2': {
                            int value;
                            cout << "Enter a value to remove: ";
                            cin >> value;
                            avlTree.remove(value);

                            cout << "AVL tree: \n" << endl;
                            avlTree.printAVLTree();
                            cout << "\n-----------------------------------------------------------------------------\n";
                            break;
                        }
                        case '3': {
                            int value;
                            cout << "Enter a value to search: ";
                            cin >> value;
                            cout << (avlTree.search(value) ? "Found\n" : "Not Found\n") << endl;

                            cout << "AVL tree: \n" << endl;
                            avlTree.printAVLTree();
                            cout << "\n-----------------------------------------------------------------------------\n";
                            break;
                        }
                        case '4': {
                            cout << "In change bypass: \n";
                            avlTree.bypassInChange();
                            cout << "\n-----------------------------------------------------------------------------\n";
                            break;
                        }
                        case '5': {
                            cout << "Direct bypass: \n";
                            avlTree.bypassDirect();
                            cout << "\n-----------------------------------------------------------------------------\n";
                            break;
                        }
                        case '6': {
                            cout << "Reverse bypass: \n";
                            avlTree.bypassReverse();
                            cout << "\n-----------------------------------------------------------------------------\n";
                            break;
                        }
                        case '7':{
                            cout << "Symmetrical bypass: \n";
                            avlTree.bypassSymmetrical();
                            cout << "\n-----------------------------------------------------------------------------\n";
                            break;
                        }
                        case '8': {
                            avlTree.clearAVLTree();
                            cout << "Tree cleaned\n";
                            cout << "\n-----------------------------------------------------------------------------\n";
                            break;
                        }
                        case '0': {
                            ex = true;
                            break;
                        }
                        default: {
                            cout << "Invalid option. Please try again\n";
                            cout << "-------------------------------------------------------------------------------\n";
                            break;
                        }
                    }
                }
                break;
            }
            case '0':{
                cout << "Exit" << endl;
                exit = true;
                break;
            }
            default:{
                cout << "Invalid option. Please try again\n";
                break;
            }
        }
    }
}



int application::menu1(){
    char ch;
    cout << "------------------------------------------------------------------------------------\n";
    cout << "-------------------------\n";
    cout << "|Binary Tree | AVL Tree |\n";
    cout << "-------------------------\n";
    cout << "Choice an option (Introduce order):\n";
    cout << "|1. Enter bracket notation manually\n";
    cout << "|2. Enter bracket notation from file\n";
    cout << "|3. Direct bypass Binary tree\n";
    cout << "|4. >> Go to AVL tree changes\n";
    cout << "|0. EXIT\n";
    cin >> ch;
    cin.ignore();
    cout << "------------------------------------------------------------------------------------\n";
    return ch;
}



int application::menu2(){
    char c;
    cout << "--------------\n";
    cout << "|| AVL Tree ||\n";
    cout << "--------------\n";
    cout << "||1. Insert an element\n";
    cout << "||2. Delete an element\n";
    cout << "||3. Search an element\n";
    cout << "||4. In change bypass\n";
    cout << "||5. Direct bypass\n";
    cout << "||6. Reverse bypass\n";
    cout << "||7. Symmetrical bypass\n";
    cout << "||8. Clear tree\n";
    cout << "||0. EXIT\n";
    cin >> c;
    cin.ignore();
    cout << "------------------------------------------------------------------------------------\n";
    return c;
}