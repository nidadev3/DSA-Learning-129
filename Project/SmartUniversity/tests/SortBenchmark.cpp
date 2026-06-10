#include <iostream>
#include <chrono>
#include "../include/SortingAlgorithms.h"
using namespace std;

void fillArray(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].rollNo = n - i;
        arr[i].name = "Student";
        arr[i].department = "CS";
        arr[i].cgpa = (float)(n - i) / 100.0;
    }
}

void copyArray(Student src[], Student dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void runBenchmark(int n) {
    SortingAlgorithms sorter;
    Student* original = new Student[n];
    Student* arr = new Student[n];
    fillArray(original, n);

    cout << "\nSize: " << n << endl;

    copyArray(original, arr, n);
    auto start = chrono::high_resolution_clock::now();
    sorter.bubbleSort(arr, n);
    auto end = chrono::high_resolution_clock::now();
    cout << "Bubble Sort:    " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " us" << endl;

    copyArray(original, arr, n);
    start = chrono::high_resolution_clock::now();
    sorter.insertionSort(arr, n);
    end = chrono::high_resolution_clock::now();
    cout << "Insertion Sort: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " us" << endl;

    copyArray(original, arr, n);
    start = chrono::high_resolution_clock::now();
    sorter.mergeSort(arr, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    cout << "Merge Sort:     " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " us" << endl;

    copyArray(original, arr, n);
    start = chrono::high_resolution_clock::now();
    sorter.quickSort(arr, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    cout << "Quick Sort:     " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " us" << endl;

    copyArray(original, arr, n);
    start = chrono::high_resolution_clock::now();
    sorter.heapSort(arr, n);
    end = chrono::high_resolution_clock::now();
    cout << "Heap Sort:      " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " us" << endl;

    delete[] original;
    delete[] arr;
}

int main() {
    cout << "===== Sorting Benchmark =====" << endl;
    runBenchmark(100);
    runBenchmark(1000);
    runBenchmark(10000);
    runBenchmark(100000);
    return 0;
}