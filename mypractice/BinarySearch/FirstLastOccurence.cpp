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
