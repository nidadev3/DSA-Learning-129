#include "../include/CircularQueue.h"
#include <iostream>
using namespace std;

CircularQueue::CircularQueue(int cap) {
    capacity = cap;
    arr = new Student[capacity];
    front = -1;
    rear = -1;
    size = 0;
}

CircularQueue::~CircularQueue() {
    delete[] arr;
}

bool CircularQueue::isEmpty() {
    return size == 0;
}

bool CircularQueue::isFull() {
    return size == capacity;
}

void CircularQueue::enqueue(Student s) {
    if (isFull()) {
        cout << "Circular Queue is full" << endl;
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = s;
    size++;
}

Student CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Circular Queue is empty" << endl;
        return Student();
    }
    Student data = arr[front];
    if (size == 1) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    size--;
    return data;
}

void CircularQueue::display() {
    if (isEmpty()) return;
    int i = front;
    int count = 0;
    while (count < size) {
        cout << arr[i].rollNo << " | " << arr[i].name << endl;
        i = (i + 1) % capacity;
        count++;
    }
}