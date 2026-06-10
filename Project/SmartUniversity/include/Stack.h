#ifndef STACK_H
#define STACK_H

#include "Student.h"

struct StackNode {
    Student data;
    StackNode* next;
    StackNode(Student s) : data(s), next(nullptr) {}
};

class Stack {
private:
    StackNode* top;
    int size;
public:
    Stack();
    ~Stack();
    void push(Student s);
    Student pop();
    Student peek();
    bool isEmpty();
    int getSize();
};

#endif