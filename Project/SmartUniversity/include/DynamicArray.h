#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Student.h"

class DynamicArray {
private:
    Student* arr;
    int size;
    int capacity;
    void resize();
public:
    DynamicArray();
    ~DynamicArray();
    void insert(Student s);
    void deleteAt(int index);
    Student getAt(int index);
    int getSize();
    void display();
};

#endif