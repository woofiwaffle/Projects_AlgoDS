#ifndef PROJECTS_ALGODS_DL_LIST_H
#define PROJECTS_ALGODS_DL_LIST_H

struct List{
    int data;
    List *head;
    List *tail;
};

List* createListRandom(int n);
List* createList();
void printList(List* head);
void insertElement(List* &head, int index, int value);
void deleteElementByIndex(List* &head, int index);
void deleteElementByValue(List* &head, int value);
void swapElements(List* &head, int index1, int index2);
int DL_List();


#endif //PROJECTS_ALGODS_DL_LIST_H
