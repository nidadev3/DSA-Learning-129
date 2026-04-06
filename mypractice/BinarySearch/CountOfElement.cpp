#include <iostream>
using namespace std;

// First Occurrence
int firstOccurrence(int arr[], int n, int key) {
    int start = 0, end = n - 1;
    int ans = -1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

// Last Occurrence
int lastOccurrence(int arr[], int n, int key) {
    int start = 0, end = n - 1;
    int ans = -1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted array elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter element to count: ";
    cin >> key;

    int first = firstOccurrence(arr, n, key);
    int last = lastOccurrence(arr, n, key);

    if(first == -1) {
        cout << "Element not found";
    } else {
        int count = last - first + 1;
        cout << "Count of element: " << count;
    }

    return 0;
}