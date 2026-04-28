#ifndef QUEUE_H
#define QUEUE_H
#include "Complaint.h"
class Queue {
private:
    Complaint arr[100];
    int front;
    int rear;
//functions
    public:
    Queue();
    void enqueue(Complaint c);
    Complaint dequeue();
    bool isEmpty();
    void display();

};
#endif