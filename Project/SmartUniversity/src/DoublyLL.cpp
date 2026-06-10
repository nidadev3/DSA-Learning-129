#include "../include/DoublyLL.h"
#include <iostream>
using namespace std;

DoublyLL::DoublyLL() {
    head = nullptr;
    current = nullptr;
}

void DoublyLL::insertFront(Student s) {
    DLLNode* newNode = new DLLNode(s);
    if (head == nullptr) {
        head = newNode;
        current = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    current = newNode;
}

void DoublyLL::goForward() {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
        displayCurrent();
    } else {
        cout << "No next record" << endl;
    }
}

void DoublyLL::goBack() {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
        displayCurrent();
    } else {
        cout << "No previous record" << endl;
    }
}

void DoublyLL::displayCurrent() {
    if (current != nullptr) {
        cout << current->data.rollNo << " | "
             << current->data.name << " | "
             << current->data.department << endl;
    }
}

void DoublyLL::display() {
    DLLNode* curr = head;
    while (curr != nullptr) {
        cout << curr->data.rollNo << " | "
             << curr->data.name << endl;
        curr = curr->next;
    }
}