#include "D_Array.h"
#include <iostream>

using namespace std;



DynamicArray::DynamicArray(int initCapacity) {
    capacity = initCapacity;
    size = 0;
    arr = new int[capacity];
}

DynamicArray::~DynamicArray() {
    delete[] arr;
}



void DynamicArray::createArrayRandom(int n) {

    if(n <= 0){
        cout << "Invalid array size" << endl;
        return;
    }
    size = n;
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
}



void DynamicArray::createArray() {

    cout << "Enter the size of the array: ";
    cin >> size;
    if(size <= 0){
        cout << "Invalid array size" << endl;
        return;
    }
    for(int i = 0; i < size; i++){
        cout << "Enter element: " << i << ": ";
        cin >> arr[i];
    }
}



void DynamicArray::printArray() {

    if(size == 0){
        std::cout << "Array is empty" << endl;
        return;
    }
    cout << "Array elements: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}



void DynamicArray::insertElement(int index, int value) {

    if(index < 0 || index > size){
        cout << "Invalid index" << endl;
        return;
    }
    if(size >= capacity){
        capacity *= 2;
        int* newArr = new int[capacity];
        for(int i = 0; i < size; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    for(int i = size; i > index; i--){
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
}



void DynamicArray::deleteElementByIndex(int index) {

    if(index < 0 || index >= size){
        cout << "Invalid index" << endl;
        return;
    }
    for(int i = index; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }
    size--;
}



void DynamicArray::deleteElementByValue(int value) {

    int index = -1;
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            index = i;
            break;
        }
    }
    if(index != -1){
        deleteElementByIndex(index);
    }
    else{
        cout << "Element with value " << value << " not found" << endl;
    }
}



void DynamicArray::swapElements(int index1, int index2) {
    if(index1 < 0 || index1 >= size || index2 < 0 || index2 >= size){
        cout << "Invalid indices" << endl;
        return;
    }
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}



int DynamicArray::D_Array() {

    srand(time(0));

    DynamicArray dynamicArray;

    int choice, index, value;

    while (true) {

        cout << "--------------------------------------------" << endl;
        cout << "|Choose an option:\n";
        cout << "|1. Create a random array\n";
        cout << "|2. Create an array from input\n";
        cout << "|3. Print array\n";
        cout << "|4. Insert an element at an index\n";
        cout << "|5. Delete an element by index\n";
        cout << "|6. Delete an element by value\n";
        cout << "|7. Swap two elements\n";
        cout << "|0. Exit\n";
        cout << ">> ";
        cin >> choice;
        cout << "--------------------------------------------" << endl;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the number of elements in the array: ";
                cin >> n;
                dynamicArray.createArrayRandom(n);
                cout << "Array created" << endl;
                break;
            }
            case 2: {
                dynamicArray.createArray();
                cout << "Array created" << endl;
                break;
            }
            case 3: {
                dynamicArray.printArray();
                break;
            }
            case 4: {
                cout << "Enter the index: ";
                cin >> index;
                cout << "Enter the value: ";
                cin >> value;
                dynamicArray.insertElement(index, value);
                break;
            }
            case 5: {
                cout << "Enter the index to delete: ";
                cin >> index;
                dynamicArray.deleteElementByIndex(index);
                break;
            }
            case 6: {
                cout << "Enter the value to delete: ";
                cin >> value;
                dynamicArray.deleteElementByValue(value);
                break;
            }
            case 7: {
                int index1, index2;
                cout << "Enter the first index: ";
                cin >> index1;
                cout << "Enter the second index: ";
                cin >> index2;
                dynamicArray.swapElements(index1, index2);
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
