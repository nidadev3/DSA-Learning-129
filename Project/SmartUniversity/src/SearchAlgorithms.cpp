#include "../include/SearchAlgorithms.h"

int SearchAlgorithms::linearSearch(Student arr[], int n, int rollNo) {
    for (int i = 0; i < n; i++) {
        if (arr[i].rollNo == rollNo) return i;
    }
    return -1;
}

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