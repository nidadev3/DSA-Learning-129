#include "../include/Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    top = nullptr;
    size = 0;
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(Student s) {
    StackNode* newNode = new StackNode(s);
    newNode->next = top;
    top = newNode;
    size++;
}

Student Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return Student();
    }
    StackNode* temp = top;
    Student data = top->data;
    top = top->next;
    delete temp;
    size--;
    return data;
}

Student Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return Student();
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

int Stack::getSize() {
    return size;
}