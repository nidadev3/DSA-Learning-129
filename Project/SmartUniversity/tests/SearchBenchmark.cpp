#include <iostream>
#include <chrono>
#include "../include/SearchAlgorithms.h"
using namespace std;

void fillSortedArray(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].rollNo = i + 1;
        arr[i].name = "Student";
        arr[i].department = "CS";
        arr[i].cgpa = 3.0;
    }
}

void runBenchmark(int n) {
    SearchAlgorithms searcher;
    Student* arr = new Student[n];
    fillSortedArray(arr, n);

    HashTable ht(n * 2);
    BST bst;
    for (int i = 0; i < n; i++) {
        ht.insert(arr[i].rollNo, arr[i]);
        bst.insert(arr[i]);
    }

    int target = n;
    cout << "\n--- Size: " << n << " ---" << endl;

    // Linear Search
    auto start = chrono::high_resolution_clock::now();
    int r1 = searcher.linearSearch(arr, n, target);
    auto end = chrono::high_resolution_clock::now();
    cout << "Linear Search  O(n):      "
         << chrono::duration_cast<chrono::microseconds>(end-start).count()
         << " us  | index: " << r1 << endl;

    // Binary Search
    start = chrono::high_resolution_clock::now();
    int r2 = searcher.binarySearch(arr, n, target);
    end = chrono::high_resolution_clock::now();
    cout << "Binary Search  O(log n):  "
         << chrono::duration_cast<chrono::microseconds>(end-start).count()
         << " us  | index: " << r2 << endl;

    // Hash Search
    start = chrono::high_resolution_clock::now();
    Student* r3 = searcher.hashSearch(ht, target);
    end = chrono::high_resolution_clock::now();
    cout << "Hash Search    O(1):      "
         << chrono::duration_cast<chrono::microseconds>(end-start).count()
         << " us  | found: " << (r3 ? "yes" : "no") << endl;

    // BST Search
    start = chrono::high_resolution_clock::now();
    Student* r4 = searcher.bstSearch(bst, target);
    end = chrono::high_resolution_clock::now();
    cout << "BST Search     O(log n):  "
         << chrono::duration_cast<chrono::microseconds>(end-start).count()
         << " us  | found: " << (r4 ? "yes" : "no") << endl;

    delete[] arr;
}

int main() {
    cout << "===== Search Benchmark — all 5 algorithms =====" << endl;
    runBenchmark(100);
    runBenchmark(1000);
    runBenchmark(10000);
    runBenchmark(100000);
    return 0;
}