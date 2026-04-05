#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
        return;
    }

    Node* ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void display() {
    Node* ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void reverseLoop() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node* ptr = prev;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void reverseRec(Node* ptr) {
    if(ptr == NULL) return;

    reverseRec(ptr->next);
    cout << ptr->data << " ";
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();

    reverseLoop();

    reverseRec(head);

    return 0;
}