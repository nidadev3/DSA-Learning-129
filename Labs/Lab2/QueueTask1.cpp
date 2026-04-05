#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;

    if(front == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if(front == NULL) return;

    Node* temp = front;
    front = front->next;

    if(front == NULL)
        rear = NULL;

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

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}