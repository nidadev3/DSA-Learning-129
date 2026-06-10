#include "../include/SinglyLL.h"
#include <iostream>
using namespace std;

SinglyLL::SinglyLL() {
    head = nullptr;
    size = 0;
}

SinglyLL::~SinglyLL() {
    SLLNode* curr = head;
    while (curr != nullptr) {
        SLLNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void SinglyLL::insertFront(string course) {
    SLLNode* newNode = new SLLNode(course);
    newNode->next = head;
    head = newNode;
    size++;
}

void SinglyLL::insertEnd(string course) {
    SLLNode* newNode = new SLLNode(course);
    if (head == nullptr) {
        head = newNode;
        size++;
        return;
    }
    SLLNode* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
    size++;
}

void SinglyLL::deleteNode(string course) {
    if (head == nullptr) return;
    if (head->courseName == course) {
        SLLNode* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }
    SLLNode* curr = head;
    while (curr->next != nullptr) {
        if (curr->next->courseName == course) {
            SLLNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            size--;
            return;
        }
        curr = curr->next;
    }
}

void SinglyLL::display() {
    SLLNode* curr = head;
    while (curr != nullptr) {
        cout << curr->courseName << endl;
        curr = curr->next;
    }
}

int SinglyLL::getSize() {
    return size;
}