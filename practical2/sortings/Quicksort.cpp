#include "Quicksort.h"
#include <iostream>


int Quicksort::part(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}



void Quicksort::utilQuicksort(int* arr, int low, int high) {
    if(low < high){
        int pi = part(arr, low, high);

        utilQuicksort(arr, low, pi - 1);
        utilQuicksort(arr, pi + 1, high);
    }
}



void Quicksort::quicksort(DynamicArray &dynamicArray) {
    int* arr = dynamicArray.getArray();
    int size = dynamicArray.getSize();
    utilQuicksort(arr, 0, size - 1);
}
