#ifndef QUEUE_H
#define QUEUE_H

#include "Student.h"

struct QueueNode {
    Student data;
    QueueNode* next;
    QueueNode(Student s) : data(s), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
    int size;
public:
    Queue();
    ~Queue();
    void enqueue(Student s);
    Student dequeue();
    Student getFront();
    bool isEmpty();
    int getSize();
};

#endif