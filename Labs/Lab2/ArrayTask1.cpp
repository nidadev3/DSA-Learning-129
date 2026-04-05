#include <iostream>
using namespace std;

int arr[100], n = 0;   
void display() {
    cout << "Array List: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void insertEnd(int value) {
    arr[n] = value;
    n++;
}


void insertStart(int value) {
    for(int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    n++;
}


void insertAfter(int target, int value) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == target) {
            break;
        }
    }

    if(i == n) {
        cout << "Value not found!\n";
        return;
    }

    for(int j = n; j > i + 1; j--) {
        arr[j] = arr[j - 1];
    }

    arr[i + 1] = value;
    n++;
}


void insertBefore(int target, int value) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == target) {
            break;
        }
    }

    if(i == n) {
        cout << "Value not found!\n";
        return;
    }

    for(int j = n; j > i; j--) {
        arr[j] = arr[j - 1];
    }

    arr[i] = value;
    n++;
}

void deleteEnd() {
    if(n > 0) {
        n--;
    }
}


void deleteStart() {
    for(int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}


void deleteValue(int value) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == value) {
            break;
        }
    }

    if(i == n) {
        cout << "Value not found!\n";
        return;
    }

    for(int j = i; j < n - 1; j++) {
        arr[j] = arr[j + 1];
    }

    n--;
}


int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    display();

    insertStart(5);
    display();

    insertAfter(20, 25);
    display();

    insertBefore(20, 15);
    display();

    deleteEnd();
    display();

    deleteStart();
    display();

    deleteValue(20);
    display();

    return 0;
}