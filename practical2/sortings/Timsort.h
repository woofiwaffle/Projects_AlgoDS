#ifndef PROJECTS_ALGODS_TIMSORT_H
#define PROJECTS_ALGODS_TIMSORT_H

#include "D_Array.h"

class Timsort{
private:
    static int Getminrun(int n);
    static void insertSort(int* arr, int left, int right);
    static void merge(int* arr, int l, int m, int r);
    static void utilTimsort(int* arr, int n);
public:
    static void timsort(DynamicArray &dynamicArray);
};

#endif //PROJECTS_ALGODS_TIMSORT_H
