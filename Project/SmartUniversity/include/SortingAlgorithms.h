#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include "Student.h"

class SortingAlgorithms {
public:
    void bubbleSort(Student arr[], int n);
    void insertionSort(Student arr[], int n);
    void mergeSort(Student arr[], int left, int right);
    void quickSort(Student arr[], int low, int high);
    void heapSort(Student arr[], int n);

private:
    void merge(Student arr[], int left, int mid, int right);
    int partition(Student arr[], int low, int high);
    void heapify(Student arr[], int n, int i);
};

#endif