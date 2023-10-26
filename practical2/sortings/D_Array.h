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
    int* getArray();
    int getSize();
};

#endif //PROJECTS_ALGODS_D_ARRAY_H
