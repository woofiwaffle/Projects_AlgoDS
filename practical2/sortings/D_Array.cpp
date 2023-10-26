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
    if(n > capacity){
        delete[] arr;
        capacity = n;
        arr = new int[capacity];
    }
    size = n;
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 199 - 99;
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
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}



int* DynamicArray::getArray() {
    return arr;
}



int DynamicArray::getSize() {
    return size;
}
