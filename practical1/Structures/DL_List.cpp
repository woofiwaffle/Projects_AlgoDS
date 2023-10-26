#include <iostream>
#include "DL_List.h"

using namespace std;



List* createListRandom(int n){
    List* head = new List();
    head->data = rand() % 100;
    head->head = nullptr;
    List *current = head;
    for (int i = 1; i < n; i++) {
        current->tail = new List();
        current->tail->data = rand() % 100;
        current->tail->head = current;
        current = current->tail;
    }
    current->head = nullptr;
    return head;
}



List* createList() {
    List* head = nullptr, *tail = nullptr;
    int n = 0, value;

    cout << "Enter the elements of the list (end with a non-integer character): ";

    while(cin >> value){
        List* newNode = new List;
        newNode->data = value;
        newNode->head = tail;
        newNode->tail = nullptr;

        if(tail != nullptr){
            tail->tail = newNode;
        }

        tail = newNode;

        if(n == 0){
            head = newNode;
        }
        n++;
    }
    cin.clear();
    cin.ignore();

    return head;
}



void printList(List* head){
    List *current = head;
    cout << "List: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->tail;
    }
    cout << endl;
}



void deleteList(List* head){
    List *current;
    while(head != nullptr){
        current = head->tail;
        delete head;
        head = current;
    }
}



void insertElement(List* &head, int index, int value){

    List *temp = new List();

    temp->data = value;

    if(head == nullptr || index <= 0){
        temp->head = nullptr;
        temp->tail = head;
        if(head != nullptr){
            head->head = temp;
        }
        head = temp;
    }
    else{
        List *current = head;

        for(int i = 0; i < index - 1 && current->tail != nullptr; i++){
            current = current->tail;
        }

        temp->head = current;
        temp->tail = current->tail;

        if(current->tail != nullptr){
            current->tail->head = temp;
        }
        current->tail = temp;
    }
}


[[maybe_unused]] void deleteElementByIndex(List* &head, int index){

    if(head == nullptr){
        return;
    }
    List *current = head;

    if(index == 0){
        head = head->tail;
        if(head != nullptr){
            head->head = nullptr;
        }
        delete current;
    }
    else{
        for(int i = 0; i < index && current != nullptr; i++){
            current = current->tail;
        }

        if(current == nullptr){
            return;
        }
        current->head->tail = current->tail;

        if(current->tail != nullptr){
            current->tail->head = current->head;
        }
        delete current;
    }
}


[[maybe_unused]] void deleteElementByValue(List* &head, int value){

    if(head == nullptr){
        return;
    }
    List *current = head;

    if(current->data == value){
        head = head->tail;
        if(head != nullptr){
            head->head = nullptr;
        }
        delete current;
        return;
    }
    while (current->tail != nullptr && current->tail->data != value){
        current = current->tail;
    }
    if(current->tail == nullptr){
        return;
    }
    List *temp = current->tail;
    current->tail = temp->tail;

    if(temp->tail != nullptr){
        temp->tail->head = current;
    }
    delete temp;
}



void swapElements(List* &head, int index1, int index2){

    if(head == nullptr || index1 == index2){
        return;
    }

    List *temp, *current1 = head, *current2 = head;

    for(int i = 0; i < index1 && current1 != nullptr; i++){
        current1 = current1->tail;
    }

    for (int i = 0; i < index2 && current2 != nullptr; i++){
        current2 = current2->tail;
    }

    if(current1 == nullptr || current2 == nullptr){
        return;
    }
    if(current2->tail == current1){
        swap(current1, current2);
    }
    if(current1->tail == current2){
        temp = current1;
        current1 = current2;
        current2 = temp;
    }
    if(current1->head != nullptr){
        current1->head->tail = current2;
    }
    if(current1->tail != nullptr){
        current1->tail->head = current2;
    }
    if(current2->head != nullptr){
        current2->head->tail = current1;
    }
    if(current2->tail != nullptr){
        current2->tail->head = current1;
    }
    temp = current1->head;
    current1->head = current2->head;

    current2->head = temp;
    temp = current1->tail;

    current1->tail = current2->tail;
    current2->tail = temp;

    if(head == current1){
        head = current2;
    }
    else if(head == current2){
        head = current1;
    }
}



int DL_List(){

    srand(time(0));

    List *head = nullptr;

    int choice, n = 0, index, value;

    while(true){

        cout << "--------------------------------------------" << endl;
        cout << "|Choose an option:\n";
        cout << "|1. Create a list of random integers.\n";
        cout << "|2. Create a list from the entered numbers.\n";
        cout << "|3. Print list.\n";
        cout << "|4. Insert an element at an index.\n";
        cout << "|5. Delete an element by index.\n";
        cout << "|6. Delete an element by value.\n";
        cout << "|7. Swap two elements.\n";
        cout << "|0. Exit.\n";
        cout << ">>...\n";
        cin >> choice;
        cout << "--------------------------------------------" << endl;

        switch(choice){
            case 1: {
                cout << "Enter the number of elements in the list: " << endl;
                cin >> n;
                head = createListRandom(n);
                cout << "List created" << endl;
                break;
            }
            case 2: {
                cout << " " << endl;
                head = createList();
                cout << "List created" << endl;
                break;
            }
            case 3: {
                if(head == nullptr){
                    cout << "List is empty" << endl;
                }
                else{
                    printList(head);
                }
                break;
            }
            case 4: {
                if(head == nullptr){
                    cout << "The list is empty.\n";
                    break;
                }
                cout << "Enter the index: ";
                cin >> index;
                cout << "Enter the value: ";
                cin >> value;
                insertElement(head, index, value);
                break;
            }
            case 5: {
                if(head == nullptr){
                    cout << "The list is empty.\n";
                    break;
                }
                cout << "Enter the index: ";
                cin >> index;
                deleteElementByIndex(head, index);
                break;
            }
            case 6: {
                if(head == nullptr){
                    cout << "The list is empty.\n";
                    break;
                }
                cout << "Enter the value: ";
                cin >> value;
                deleteElementByValue(head, value);
                break;
            }
            case 7: {
                if(head == nullptr){
                    cout << "The list is empty.\n";
                    break;
                }
                cout << "Enter the first index: ";
                cin >> index;
                cout << "Enter the second index: ";
                cin >> value;
                swapElements(head, index, value);
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                cout << "Invalid choice.\n";
                break;
            }
        }
    }
}
