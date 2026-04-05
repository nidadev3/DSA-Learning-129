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

void insertStart(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = head;
    head = temp;
}

void display() {
    Node* ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void insertAfter(int target, int value) {
    Node* ptr = head;
    while(ptr != NULL && ptr->data != target) {
        ptr = ptr->next;
    }

    if(ptr == NULL) return;

    Node* temp = new Node();
    temp->data = value;
    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteFirst() {
    if(head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteLast() {
    if(head == NULL) return;

    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* ptr = head;
    while(ptr->next->next != NULL) {
        ptr = ptr->next;
    }

    delete ptr->next;
    ptr->next = NULL;
}

void deleteValue(int value) {
    if(head == NULL) return;

    if(head->data == value) {
        deleteFirst();
        return;
    }

    Node* ptr = head;
    while(ptr->next != NULL && ptr->next->data != value) {
        ptr = ptr->next;
    }

    if(ptr->next == NULL) return;

    Node* temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

void deleteAll() {
    Node* ptr = head;

    while(ptr != NULL) {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    head = NULL;
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    display();

    insertStart(5);
    display();

    insertAfter(20, 25);
    display();

    deleteFirst();
    display();

    deleteLast();
    display();

    deleteValue(20);
    display();

    deleteAll();
    display();

    return 0;
}