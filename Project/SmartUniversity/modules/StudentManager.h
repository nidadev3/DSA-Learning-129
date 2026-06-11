#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "../include/DynamicArray.h"
#include "../include/HashTable.h"
#include "../include/AVLTree.h"
#include "../include/BST.h"
#include "../include/SortingAlgorithms.h"
#include "../include/SearchAlgorithms.h"
#include "../include/FileManager.h"

class StudentManager {
private:
    DynamicArray dynamicArray;
    HashTable hashTable;
    AVLTree avlTree;
    BST bst;
    SortingAlgorithms sorter;
    SearchAlgorithms searcher;
    FileManager fileManager;
public:
    int getSize();
    Student* getArray();
    void addStudent(Student s);
    void deleteStudent(int rollNo);
    void searchByRollNo(int rollNo);
    void displayAll();
    void displaySortedByCGPA();
    void saveToFile();
    void loadFromFile();
};

#endif