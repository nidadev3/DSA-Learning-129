#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Selection Sort
    for(int i = 0; i < n - 1; i++){
        int min = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        // Swap
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}