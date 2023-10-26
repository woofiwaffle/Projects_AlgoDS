#include "application.h"
#include "sortings/D_Array.h"
#include "sortings/Quicksort.h"
#include "sortings/Timsort.h"

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;



int application::exec() {

    DynamicArray dynamicArray;
    int n;
    auto start = steady_clock::now();
    auto end = steady_clock::now();
    auto result = duration_cast<nanoseconds>(end - start);

    char ch;
    bool exit = false;
    while(!exit){
        ch = menu();
        switch(ch){
            case '1': {
                cout << "Do you want random elements (Y - yes / N - no) ? : ";
                char option;
                cin >> option;
                if(option == 'Y' || option == 'y'){
                    cout << "Enter the number of elements in the array: ";
                    cin >> n;
                    dynamicArray.createArrayRandom(n);
                    cout << endl;
                    cout << "Original array: " << endl;
                    dynamicArray.printArray();
                }
                else{
                    dynamicArray.createArray();
                    cout << endl;
                    cout << "Original array: " << endl;
                    dynamicArray.printArray();
                }
                start = steady_clock::now();
                Timsort::timsort(dynamicArray);
                cout << "\nSorted array: " << endl;
                dynamicArray.printArray();
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\nTime: " << result.count() << " ns" << "\n";
                break;
            }
            case '2': {
                cout << "Do you want random elements (Y - yes / N - no) ? : ";
                char option;
                cin >> option;
                if(option == 'Y' || option == 'y'){
                    cout << "Enter the number of elements in the array: ";
                    cin >> n;
                    dynamicArray.createArrayRandom(n);
                    cout << endl;
                    cout << "Original array: " << endl;
                    dynamicArray.printArray();
                }
                else{
                    dynamicArray.createArray();
                    cout << endl;
                    cout << "Original array: " << endl;
                    dynamicArray.printArray();
                }
                start = steady_clock::now();
                Quicksort::quicksort(dynamicArray);
                cout << "\nSorted array: " << endl;
                dynamicArray.printArray();
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\nTime: " << result.count() << " ns" << "\n";
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
    cout << "|1 - TimSort" << endl;
    cout << "|2 - Quick sort" << endl;
    cout << "|0 - Exit" << endl << "> ";
    cin >> ch;
    cin.ignore();
    cout << "--------------------------------------------" << endl;
    return ch;
}
