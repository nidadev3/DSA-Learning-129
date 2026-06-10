#ifndef MINHEAP_H
#define MINHEAP_H

#include "Student.h"

class MinHeap {
private:
    Student* arr;
    int size;
    int capacity;
    void heapifyUp(int index);
    void heapifyDown(int index);
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
public:
    MinHeap(int cap = 100);
    ~MinHeap();
    void insert(Student s);
    Student extractMin();
    Student getMin();
    bool isEmpty();
    void display();
};

#endif