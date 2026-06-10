#include "../include/MinHeap.h"
#include <iostream>
using namespace std;

MinHeap::MinHeap(int cap) {
    capacity = cap;
    size = 0;
    arr = new Student[capacity];
}

MinHeap::~MinHeap() {
    delete[] arr;
}

int MinHeap::parent(int i) { return (i - 1) / 2; }
int MinHeap::leftChild(int i) { return 2 * i + 1; }
int MinHeap::rightChild(int i) { return 2 * i + 2; }

void MinHeap::heapifyUp(int index) {
    while (index > 0 && arr[parent(index)].cgpa > arr[index].cgpa) {
        swap(arr[parent(index)], arr[index]);
        index = parent(index);
    }
}

void MinHeap::heapifyDown(int index) {
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);
    if (left < size && arr[left].cgpa < arr[smallest].cgpa)
        smallest = left;
    if (right < size && arr[right].cgpa < arr[smallest].cgpa)
        smallest = right;
    if (smallest != index) {
        swap(arr[smallest], arr[index]);
        heapifyDown(smallest);
    }
}

void MinHeap::insert(Student s) {
    if (size == capacity) {
        cout << "Heap is full" << endl;
        return;
    }
    arr[size] = s;
    heapifyUp(size);
    size++;
}

Student MinHeap::extractMin() {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
        return Student();
    }
    Student minVal = arr[0];
    arr[0] = arr[size - 1];
    size--;
    heapifyDown(0);
    return minVal;
}

Student MinHeap::getMin() {
    return arr[0];
}

bool MinHeap::isEmpty() {
    return size == 0;
}

void MinHeap::display() {
    for (int i = 0; i < size; i++) {
        cout << arr[i].rollNo << " | "
             << arr[i].name << " | "
             << arr[i].cgpa << endl;
    }
}