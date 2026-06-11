#include "../include/SearchAlgorithms.h"
#include <iostream>
using namespace std;

// Search 1: Linear Search — O(n)
int SearchAlgorithms::linearSearch(Student arr[], int n, int rollNo) {
    for (int i = 0; i < n; i++) {
        if (arr[i].rollNo == rollNo) return i;
    }
    return -1;
}

// Search 2: Binary Search — O(log n) — array must be sorted
int SearchAlgorithms::binarySearch(Student arr[], int n, int rollNo) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].rollNo == rollNo) return mid;
        else if (arr[mid].rollNo < rollNo) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Search 3: Hash Search — O(1) average
Student* SearchAlgorithms::hashSearch(HashTable& ht, int rollNo) {
    return ht.search(rollNo);
}

// Search 4: BST Search — O(log n) average, O(n) worst
Student* SearchAlgorithms::bstSearch(BST& bst, int rollNo) {
    return bst.search(rollNo);
}

// Search 5: BFS Search — O(V+E)
void SearchAlgorithms::bfsSearch(Graph& g, int start) {
    g.BFS(start);
}

// Search 6: DFS Search — O(V+E)
void SearchAlgorithms::dfsSearch(Graph& g, int start) {
    g.DFS(start);
}