#ifndef PROJECTS_ALGODS_D_ARRAY_H
#define PROJECTS_ALGODS_D_ARRAY_H

class DynamicArray {
private:
    int *arr;
    int size;
    int capacity;

public:
    DynamicArray(int initCapacity = 10);
    ~DynamicArray();

    void createArrayRandom(int n);
    void createArray();
    void printArray();
    void insertElement(int index, int value);
    void deleteElementByIndex(int index);
    void deleteElementByValue(int value);
    void swapElements(int index1, int index2);
    static int D_Array();
};


#endif //PROJECTS_ALGODS_D_ARRAY_H
