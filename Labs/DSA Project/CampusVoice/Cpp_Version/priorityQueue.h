#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Complaint.h"
class PriorityQueue {
private:
    Complaint arr[100];
    int size;

    public:
    //constructor
    PriorityQueue();
    //functions
    void enqueue(Complaint c);
    Complaint dequeue();
    bool isEmpty();
    void display();

};
#endif