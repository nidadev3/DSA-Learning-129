#ifndef DOUBLYLL_H
#define DOUBLYLL_H

#include "Student.h"

struct DLLNode {
    Student data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(Student s) : data(s), prev(nullptr), next(nullptr) {}
};

class DoublyLL {
private:
    DLLNode* head;
    DLLNode* current;
public:
    DoublyLL();
    void insertFront(Student s);
    void goForward();
    void goBack();
    void displayCurrent();
    void display();
};

#endif