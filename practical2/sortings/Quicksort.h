#ifndef PROJECTS_ALGODS_QUICKSORT_H
#define PROJECTS_ALGODS_QUICKSORT_H

#include "D_Array.h"

class Quicksort {
private:
    static int part(int* arr, int low, int high);
    static void utilQuicksort(int* arr, int low, int high);

public:
    static void quicksort(DynamicArray &dynamicArray);
};


#endif //PROJECTS_ALGODS_QUICKSORT_H
