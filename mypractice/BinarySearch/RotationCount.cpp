#include <iostream>
using namespace std;

int findRotationCount(int arr[], int n) {
    int start = 0, end = n - 1;

    while(start <= end) {

   
        if(arr[start] <= arr[end]) {
            return start;
        }

        int mid = (start + end) / 2;

        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

       
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
            return mid;
        }

        
        else if(arr[mid] >= arr[start]) {
            start = mid + 1;
        }

        
        else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {4, 5, 1, 2, 3};
    int n = 5;

    int rotations = findRotationCount(arr, n);

    cout << "Array is rotated " << rotations << " times";

    return 0;
}