#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Complaint.h"

struct Node {
    Complaint data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void insert(Complaint c);
    void display();
};

#endif