#ifndef PROJECTS_ALGODS_STACK_H
#define PROJECTS_ALGODS_STACK_H

#include <vector>

class Stack {
private:
    std::vector<int> elements;

public:
    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    void printStack() const;
    int sizeStack() const;
    static int kStack();
};

#endif //PROJECTS_ALGODS_STACK_H
