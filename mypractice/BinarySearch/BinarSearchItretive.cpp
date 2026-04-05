#include <iostream>
using namespace std;

int main() {
    // Array input
    int n;
    cout << "Enter the capacity of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

   
    cout << "\nSorted array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
cout<<endl;
    
    int target;
    cout << "Enter the element you want to search: "<<endl;
    cin >> target;

    int start = 0;
    int end = n - 1;
    int mid;
    bool found = false;

    while(start <= end) {
        mid = (start + end) / 2;

        if(arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            found = true;
            break;
        }
        else if(arr[mid] < target) {
            start = mid + 1;  
        }
        else {
            end = mid - 1;     
        }
    }

    if(!found) {
        cout << "Element not found in array.\n";
    }

    return 0;
}