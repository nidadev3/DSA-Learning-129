#include "../include/DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray() {
    capacity = 2;
    size = 0;
    arr = new Student[capacity];
}

DynamicArray::~DynamicArray() {
    delete[] arr;
}

void DynamicArray::resize() {
    capacity = capacity * 2;
    Student* newArr = new Student[capacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

void DynamicArray::insert(Student s) {
    if (size == capacity) {
        resize();
    }
    arr[size] = s;
    size++;
}

void DynamicArray::deleteAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

Student DynamicArray::getAt(int index) {
    return arr[index];
}

int DynamicArray::getSize() {
    return size;
}

void DynamicArray::display() {
    for (int i = 0; i < size; i++) {
        cout << arr[i].rollNo << " | "
             << arr[i].name << " | "
             << arr[i].department << " | "
             << arr[i].cgpa << endl;
    }
}