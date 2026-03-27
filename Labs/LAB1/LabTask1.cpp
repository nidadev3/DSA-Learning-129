#include <iostream>
using namespace std;

class Array {
private:
    int arr[100];
    int size;

public:
    // Constructor
    Array() {
        size = 0;
    }

    // Input elements
    void input() {
        cout << "Enter number of elements: ";
        cin >> size;

        if (size <= 0 || size > 100) {
            cout << "Invalid size or array is empty\n";
            size = 0;
            return;
        }

        cout << "Enter elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Display array
    void display() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Traverse 
    void traverse() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Sum of elements
    void sum() {
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += arr[i];
        }
        cout << "Sum = " << total << endl;
    }

    // Display even elements
    void displayEven() {
        cout << "Even elements: ";
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 0) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    // Insert at end
    void insertEnd(int value) {
        if (size >= 100) {
            cout << "Array is full\n";
            return;
        }
        arr[size] = value;
        size++;
    }

    // Insert at start
    void insertStart(int value) {
        if (size >= 100) {
            cout << "Array is full\n";
            return;
        }

        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = value;
        size++;
    }

    // Insert at specific position
    void insertAt(int pos, int value) {
        if (pos < 0 || pos > size || size >= 100) {
            cout << "Invalid position or array full\n";
            return;
        }

        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = value;
        size++;
    }

    // Delete from end
    void deleteEnd() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }
        size--;
    }

    // Delete from start
    void deleteStart() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Delete from specific position
    void deleteAt(int pos) {
        if (size == 0 || pos < 0 || pos >= size) {
            cout << "Invalid position or empty array\n";
            return;
        }

        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Linear search
    void linearSearch(int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element found at index " << i << endl;
                return;
            }
        }
        cout << "Element not found\n";
    }
};

int main() {
    Array obj;
    int choice, value, pos, key;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Input\n2. Display\n3. Traverse\n4. Sum\n5. Even Elements\n";
        cout << "6. Insert End\n7. Insert Start\n8. Insert at Position\n";
        cout << "9. Delete End\n10. Delete Start\n11. Delete at Position\n";
        cout << "12. Linear Search\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.input();
                break;

            case 2:
                obj.display();
                break;

            case 3:
                obj.traverse();
                break;

            case 4:
                obj.sum();
                break;

            case 5:
                obj.displayEven();
                break;

            case 6:
                cout << "Enter value: ";
                cin >> value;
                obj.insertEnd(value);
                break;

            case 7:
                cout << "Enter value: ";
                cin >> value;
                obj.insertStart(value);
                break;

            case 8:
                cout << "Enter position and value: ";
                cin >> pos >> value;
                obj.insertAt(pos, value);
                break;

            case 9:
                obj.deleteEnd();
                break;

            case 10:
                obj.deleteStart();
                break;

            case 11:
                cout << "Enter position: ";
                cin >> pos;
                obj.deleteAt(pos);
                break;

            case 12:
                cout << "Enter element to search: ";
                cin >> key;
                obj.linearSearch(key);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}