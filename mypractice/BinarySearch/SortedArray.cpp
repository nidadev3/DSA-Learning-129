#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = 5;

    bool isSorted = true;

    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }

    if(isSorted)
        cout << "Array is sorted (ascending)";
    else
        cout << "Array is NOT sorted";

    return 0;
}

