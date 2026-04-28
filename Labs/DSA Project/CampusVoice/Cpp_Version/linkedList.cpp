#include <iostream>
#include "LinkedList.h"

using namespace std;

// Constructor
LinkedList::LinkedList() {
    head = NULL;
}

//insert add at end
void LinkedList::insert(Complaint c) {
    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = NULL;

    // if empty list
    if (head == NULL) {
        head = newNode;
        return;
    }

    // traverse to last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}