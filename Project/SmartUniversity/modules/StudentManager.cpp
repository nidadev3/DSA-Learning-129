#include "StudentManager.h"
#include <iostream>
using namespace std;

void StudentManager::addStudent(Student s) {
    dynamicArray.insert(s);
    hashTable.insert(s.rollNo, s);
    avlTree.insert(s);
    bst.insert(s);
}

void StudentManager::deleteStudent(int rollNo) {
    hashTable.remove(rollNo);
    bst.remove(rollNo);
    cout << "Student " << rollNo << " deleted" << endl;
}

void StudentManager::searchByRollNo(int rollNo) {
    Student* result = hashTable.search(rollNo);
    if (result != nullptr) {
        cout << "Found: " << result->rollNo << " | "
             << result->name << " | "
             << result->department << " | "
             << result->cgpa << endl;
    } else {
        cout << "Student not found" << endl;
    }
}

void StudentManager::displayAll() {
    cout << "--- All Students ---" << endl;
    dynamicArray.display();
}

void StudentManager::displaySortedByCGPA() {
    cout << "--- Sorted by CGPA ---" << endl;
    avlTree.inorder();
}

void StudentManager::saveToFile() {
    int size = dynamicArray.getSize();
    Student* arr = new Student[size];
    for (int i = 0; i < size; i++) {
        arr[i] = dynamicArray.getAt(i);
    }
    fileManager.saveStudents(arr, size, "data/students.txt");
    delete[] arr;
    cout << "Saved to file" << endl;
}

void StudentManager::loadFromFile() {
    Student arr[1000];
    int size = 0;
    fileManager.loadStudents(arr, size, "data/students.txt");
    for (int i = 0; i < size; i++) {
        addStudent(arr[i]);
    }
    cout << "Loaded " << size << " students" << endl;
}