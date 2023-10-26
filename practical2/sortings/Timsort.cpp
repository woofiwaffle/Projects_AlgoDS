#include "Timsort.h"
#include <algorithm>

const int MIN_RUN = 64;



int Timsort::Getminrun(int n){
    int r = 0;
    while(n >= MIN_RUN){
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}



void Timsort::insertSort(int* arr, int left, int right) {
    for(int i = left + 1; i <= right; i++){
        int temp = arr[i];
        int j = i - 1;
        while(j >= left && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}



void Timsort::merge(int* arr, int lf, int mid, int rght) {
    int length1 = mid - lf + 1;
    int length2 = rght - mid;

    int* left = new int[length1];
    int* right = new int[length2];

    for(int i = 0; i < length1; i++){
        left[i] = arr[lf + i];
    }
    for(int i = 0; i < length2; i++){
        right[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = lf;
    while(i < length1 && j < length2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }

    while(i < length1){
        arr[k++] = left[i++];
    }

    while(j < length2){
        arr[k++] = right[j++];
    }
    delete[] left;
    delete[] right;
}



void Timsort::utilTimsort(int* arr, int n) {
    int minrun = Getminrun(n);

    for(int i = 0; i < n; i += minrun){
        insertSort(arr, i, std::min(i + minrun - 1, n - 1));
    }

    for(int size = minrun; size < n; size = 2 * size){
        for(int left = 0; left < n; left += 2 * size){
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));
            merge(arr, left, mid, right);
        }
    }
}



void Timsort::timsort(DynamicArray &dynamicArray) {
    utilTimsort(dynamicArray.getArray(), dynamicArray.getSize());
}