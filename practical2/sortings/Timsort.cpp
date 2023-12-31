#include "Timsort.h"


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



void Timsort::merge(int* arr, int lf, int mid, int rght){
    int length1 = mid - lf + 1;
    int length2 = rght - mid;

    int* left = new int[length1];
    int* right = new int[length2];

    for(int i = 0; i < length1; i++){
        left[i] = arr[lf + i];
    }
    for(int i = 0; i < length2; i++){
        right[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = lf;

    while(i < length1 && j < length2){
        if(left[i] <= right[j]){
            int gallopInd = 0;
            while(j + gallopInd < length2 && left[i] > right[j + gallopInd]){
                gallopInd = gallopInd * 2 + 1;
            }
            gallopInd = std::min(gallopInd, length2 - j);
            while(gallopInd > 0){
                arr[k++] = right[j++];
                gallopInd--;
            }
            arr[k++] = left[i++];
        }
        else{
            int gallopInd = 0;
            while(i + gallopInd < length1 && right[j] >= left[i + gallopInd]){
                gallopInd = gallopInd * 2 + 1;
            }
            gallopInd = std::min(gallopInd, length1 - i);
            while(gallopInd > 0){
                arr[k++] = left[i++];
                gallopInd--;
            }
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
        insertSort(arr, i, std::min((i + minrun - 1), (n - 1)));
    }

    for(int size = minrun; size < n; size = 2 * size){
        for(int left = 0; left < n; left += 2 * size){
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));

            if(mid < right){
                merge(arr, left, mid, right);
            }
        }

    }
}



void Timsort::timsort(DynamicArray& dynamicArray) {
    int* arr = dynamicArray.getArray();
    int n = dynamicArray.getSize();
    utilTimsort(arr, n);
}