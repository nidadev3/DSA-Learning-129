#include <iostream>
using namespace std;

int search(int arr[], int n, int key) {
    int start = 0, end = n - 1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(arr[mid] == key) {
            return mid;
        }

        if(arr[start] <= arr[mid]) {

            if(key >= arr[start] && key < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        else {

            if(key > arr[mid] && key <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    int key = 0;

    int result = search(arr, n, key);

    if(result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}