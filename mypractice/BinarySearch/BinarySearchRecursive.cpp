#include <iostream>
using namespace std;


int binarySearch(int arr[], int start, int end, int target) {

    if(start > end) {
        return -1;  
    }

    int mid = (start + end) / 2;

    if(arr[mid] == target) {
        return mid;
    }
    else if(arr[mid] < target) {
        return binarySearch(arr, mid + 1, end, target);
    }
    else {
        return binarySearch(arr, start, mid - 1, target);
    }
}

int main() {

    int arr[] = {2, 4, 5, 7, 10, 15, 20};
    int n = 7;

    int target = 15;  

    cout << "Array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nSearching for: " << target << endl;

    int result = binarySearch(arr, 0, n - 1, target);

    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    }
    else {
        cout << "Element not found.\n";
    }

    return 0;
}