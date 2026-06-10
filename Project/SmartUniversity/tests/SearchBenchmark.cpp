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
    int target = n;

    cout << "\nSize: " << n << endl;

    auto start = chrono::high_resolution_clock::now();
    searcher.linearSearch(arr, n, target);
    auto end = chrono::high_resolution_clock::now();
    cout << "Linear Search: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " us" << endl;

    start = chrono::high_resolution_clock::now();
    searcher.binarySearch(arr, n, target);
    end = chrono::high_resolution_clock::now();
    cout << "Binary Search: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " us" << endl;

    delete[] arr;
}

int main() {
    cout << "===== Search Benchmark =====" << endl;
    runBenchmark(100);
    runBenchmark(1000);
    runBenchmark(10000);
    runBenchmark(100000);
    return 0;
}