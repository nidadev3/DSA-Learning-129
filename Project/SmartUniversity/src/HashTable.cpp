#include "../include/HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int cap) {
    capacity = cap;
    buckets = new HashNode*[capacity];
    for (int i = 0; i < capacity; i++) {
        buckets[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        HashNode* curr = buckets[i];
        while (curr != nullptr) {
            HashNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] buckets;
}

int HashTable::hashFunction(int key) {
    return key % capacity;
}

void HashTable::insert(int rollNo, Student s) {
    int index = hashFunction(rollNo);
    HashNode* newNode = new HashNode(rollNo, s);
    newNode->next = buckets[index];
    buckets[index] = newNode;
}

Student* HashTable::search(int rollNo) {
    int index = hashFunction(rollNo);
    HashNode* curr = buckets[index];
    while (curr != nullptr) {
        if (curr->key == rollNo) {
            return &curr->data;
        }
        curr = curr->next;
    }
    return nullptr;
}

void HashTable::remove(int rollNo) {
    int index = hashFunction(rollNo);
    HashNode* curr = buckets[index];
    HashNode* prev = nullptr;
    while (curr != nullptr) {
        if (curr->key == rollNo) {
            if (prev == nullptr) {
                buckets[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void HashTable::display() {
    for (int i = 0; i < capacity; i++) {
        HashNode* curr = buckets[i];
        while (curr != nullptr) {
            cout << curr->key << " | "
                 << curr->data.name << " | "
                 << curr->data.department << " | "
                 << curr->data.cgpa << endl;
            curr = curr->next;
        }
    }
}