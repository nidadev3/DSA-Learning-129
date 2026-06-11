#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include "Student.h"
#include "HashTable.h"
#include "BST.h"
#include "Graph.h"

class SearchAlgorithms {
public:
    // Search 1: Linear Search
    int linearSearch(Student arr[], int n, int rollNo);

    // Search 2: Binary Search (array must be sorted)
    int binarySearch(Student arr[], int n, int rollNo);

    // Search 3: Hash Search
    Student* hashSearch(HashTable& ht, int rollNo);

    // Search 4: BST Search
    Student* bstSearch(BST& bst, int rollNo);

    // Search 5: BFS Search (graph node by name)
    void bfsSearch(Graph& g, int start);

    // Search 6: DFS Search (graph node by name)
    void dfsSearch(Graph& g, int start);
};

#endif