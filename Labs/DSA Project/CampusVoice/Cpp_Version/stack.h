#ifndef STACK_H
#define STACK_H

#include "Complaint.h"

class Stack {
private:
    Complaint arr[100];
    int top;

    public:
    //constructor
    Stack();
    void push(Complaint c);
    Complaint pop();
    bool isEmpty();
    void display();
};
#endif