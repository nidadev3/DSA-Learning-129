#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* front = NULL;
Node* rear = NULL;

void insertFront(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = front;
    temp->prev = NULL;

    if(front == NULL) {
        front = rear = temp;
        return;
    }

    front->prev = temp;
    front = temp;
}

void insertRear(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;
    temp->prev = rear;

    if(rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void deleteFront() {
    if(front == NULL) return;

    Node* temp = front;
    front = front->next;

    if(front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    delete temp;
}

void deleteRear() {
    if(rear == NULL) return;

    Node* temp = rear;
    rear = rear->prev;

    if(rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    delete temp;
}

void display() {
    Node* ptr = front;

    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

int main() {

    insertFront(10);
    insertRear(20);
    insertFront(5);

    display();

    deleteFront();
    display();

    deleteRear();
    display();

    return 0;
}