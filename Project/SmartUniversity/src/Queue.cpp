#include "../include/Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(Student s) {
    QueueNode* newNode = new QueueNode(s);
    if (rear == nullptr) {
        front = newNode;
        rear = newNode;
        size++;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    size++;
}

Student Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return Student();
    }
    QueueNode* temp = front;
    Student data = front->data;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    size--;
    return data;
}

Student Queue::getFront() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return Student();
    }
    return front->data;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

int Queue::getSize() {
    return size;
}