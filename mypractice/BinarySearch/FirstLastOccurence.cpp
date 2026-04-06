#include<iostream>
using namespace std;

//SortArray
void sortArray(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//FirstOccurance
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


//LastOccurence
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

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortArray(arr, n);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int key;
    cout << "\nEnter element to search: ";
    cin >> key;

    
    int first = firstOccurrence(arr, n, key);
    int last = lastOccurrence(arr, n, key);

    if(first == -1) {
        cout << "Element not found";
    } else {
        cout << "\nFirst Occurrence Index: " << first;
        cout << "\nLast Occurrence Index: " << last;

        int total = last - first + 1;
        cout << "\nTotal Occurrences: " << total;
    }

    return 0;
}
