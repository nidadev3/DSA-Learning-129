#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include "Student.h"

class CircularQueue {
private:
    Student* arr;
    int front;
    int rear;
    int size;
    int capacity;
public:
    CircularQueue(int cap = 10);
    ~CircularQueue();
    void enqueue(Student s);
    Student dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

#endif