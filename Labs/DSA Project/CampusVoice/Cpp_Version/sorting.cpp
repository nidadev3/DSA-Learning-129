#include <iostream>
#include "Sorting.h"
 
using namespace std;
 
// ==================== BUBBLE SORT ====================
// Compare adjacent elements, swap if out of order
// Time: O(n^2)
void Sorting::bubbleSort(Complaint arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                Complaint temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Complaints sorted by ID using Bubble Sort!\n";
}
 
// ==================== SELECTION SORT ====================
// Find minimum, place at correct position
// Time: O(n^2)
void Sorting::selectionSort(Complaint arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].category < arr[minIdx].category) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Complaint temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
    cout << "Complaints sorted by Category using Selection Sort!\n";
}
 
// ==================== INSERTION SORT ====================
// Build sorted array one element at a time
// Time: O(n^2)
void Sorting::insertionSort(Complaint arr[], int n) {
    for (int i = 1; i < n; i++) {
        Complaint key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].status > key.status) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "Complaints sorted by Status using Insertion Sort!\n";
}
 
// ==================== MERGE SORT ====================
// Divide and conquer — split, sort, merge
// Time: O(n log n)
void Sorting::merge(Complaint arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    Complaint* L = new Complaint[n1];
    Complaint* R = new Complaint[n2];
 
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
 
    int i = 0, j = 0, k = left;
 
    while (i < n1 && j < n2) {
        if (L[i].id <= R[j].id) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
 
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
 
    delete[] L;
    delete[] R;
}
 
void Sorting::mergeSort(Complaint arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
 
// ==================== QUICK SORT ====================
// Pick pivot, partition around it, recurse
// Time: O(n log n) average
int Sorting::partition(Complaint arr[], int low, int high) {
    int pivot = arr[high].id;
    int i = low - 1;
 
    for (int j = low; j < high; j++) {
        if (arr[j].id <= pivot) {
            i++;
            Complaint temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
 
    Complaint temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
 
    return i + 1;
}
 
void Sorting::quickSort(Complaint arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
// ==================== HEAP SORT ====================
// Build max heap, extract max repeatedly
// Time: O(n log n)
void Sorting::heapify(Complaint arr[], int n, int i) {
    int largest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < n && arr[left].id > arr[largest].id)
        largest = left;
 
    if (right < n && arr[right].id > arr[largest].id)
        largest = right;
 
    if (largest != i) {
        Complaint temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
 
void Sorting::heapSort(Complaint arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        Complaint temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
    cout << "Complaints sorted by ID using Heap Sort!\n";
}
 
// ==================== DISPLAY ====================
void Sorting::display(Complaint arr[], int n) {
    if (n == 0) {
        cout << "No complaints to display!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << "ID: "       << arr[i].id          << endl;
        cout << "Name: "     << arr[i].studentName  << endl;
        cout << "Category: " << arr[i].category     << endl;
        cout << "Status: "   << arr[i].status       << endl;
        cout << "Urgent: "   << (arr[i].isUrgent ? "Yes" : "No") << endl;
        cout << "-------------------\n";
    }
}
 
// ==================== SORT MENU ====================
void Sorting::sortMenu(Complaint arr[], int n) {
    if (n == 0) {
        cout << "No complaints to sort!\n";
        return;
    }
 
    int choice;
    cout << "\n===== SORT COMPLAINTS =====\n";
    cout << "1. Bubble Sort   (by ID)\n";
    cout << "2. Selection Sort (by Category)\n";
    cout << "3. Insertion Sort (by Status)\n";
    cout << "4. Merge Sort    (by ID)\n";
    cout << "5. Quick Sort    (by ID)\n";
    cout << "6. Heap Sort     (by ID)\n";
    cout << "Enter choice: ";
    cin >> choice;
 
    if      (choice == 1) bubbleSort(arr, n);
    else if (choice == 2) selectionSort(arr, n);
    else if (choice == 3) insertionSort(arr, n);
    else if (choice == 4) { mergeSort(arr, 0, n - 1); cout << "Complaints sorted by ID using Merge Sort!\n"; }
    else if (choice == 5) { quickSort(arr, 0, n - 1); cout << "Complaints sorted by ID using Quick Sort!\n"; }
    else if (choice == 6) heapSort(arr, n);
    else { cout << "Invalid choice!\n"; return; }
 
    cout << "\n--- Sorted Results ---\n";
    display(arr, n);
}
 