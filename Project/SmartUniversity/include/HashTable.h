#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Student.h"

struct HashNode {
    int key;
    Student data;
    HashNode* next;
    HashNode(int k, Student s) : key(k), data(s), next(nullptr) {}
};

class HashTable {
private:
    HashNode** buckets;
    int capacity;
    int hashFunction(int key);
public:
    HashTable(int cap = 100);
    ~HashTable();
    void insert(int rollNo, Student s);
    Student* search(int rollNo);
    void remove(int rollNo);
    void display();
};

#endif