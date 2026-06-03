#ifndef SORTING_H
#define SORTING_H
 
#include "Complaint.h"
 
class Sorting {
public:
    // 6 Sorting Algorithms
    void bubbleSort(Complaint arr[], int n);
    void selectionSort(Complaint arr[], int n);
    void insertionSort(Complaint arr[], int n);
    void mergeSort(Complaint arr[], int left, int right);
   
    // Display
    void display(Complaint arr[], int n);
 
    // Sort Menu
    void sortMenu(Complaint arr[], int n);
 
private:
    // Helpers
    void merge(Complaint arr[], int left, int mid, int right);
};
 
#endif