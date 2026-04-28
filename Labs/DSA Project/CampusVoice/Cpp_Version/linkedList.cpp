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

//display of the history
void LinkedList::display() {
    if (head == NULL) {
        cout << "No history available!" << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL) {
        cout << "ID: " << temp->data.id << endl;
        cout << "Name: " << temp->data.studentName << endl;
        cout << "Category: " << temp->data.category << endl;
        cout << "Urgent: " << (temp->data.isUrgent ? "Yes" : "No") << endl;
        cout << "Status: " << temp->data.status << endl;
        cout << "-------------------" << endl;

        temp = temp->next;
    }
}