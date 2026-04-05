#include <iostream>
using namespace std;

int arr[100], n = 0;

void insertEnd(int value) {
    arr[n] = value;
    n++;
}

void display() {
    cout << "Array List: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void linearSearch(int key) {
    int i = 0;

    while(i < n) {
        if(arr[i] == key) {
            cout << "Value found at index: " << i << endl;
            return;
        }
        i++;
    }

    cout << "Value not found!" << endl;
}


int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    linearSearch(key);

    return 0;
}