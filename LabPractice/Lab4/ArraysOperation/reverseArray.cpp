#include<iostream>
using namespace std;

int main() {
    int arr[100];
    int n;

    //  Input array size
    cout << "Enter the size of array: ";
    cin >> n;

    //  Input array elements
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //  Print array before reversing
    cout << "Array before reversing: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reverse the array
    int start = 0;      
    int end = n - 1;     

    while(start < end) {
        // swap 
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // move pointers
        start++;
        end--;
    }

    //  Print array after reversing
    cout << "Array after reversing: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}