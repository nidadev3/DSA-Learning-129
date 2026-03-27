#include <iostream>
using namespace std;

class ArrayList {
private:
    int* arr;   
    int size;   
    int capacity; 

public:
    
    ArrayList(int cap = 10) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

  
    ~ArrayList() {
        delete[] arr;
    }

    // Resize array when full
    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    // Display
    void display() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Insert at end
    void insertEnd(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size] = value;
        size++;
    }

    // Insert at start
    void insertStart(int value) {
        if (size == capacity) {
            resize();
        }

        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = value;
        size++;
    }

    // Insert after specific value
    void insertAfter(int key, int value) {
        int pos = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Value not found\n";
            return;
        }

        if (size == capacity) {
            resize();
        }

        for (int i = size; i > pos + 1; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos + 1] = value;
        size++;
    }

    // Insert before specific value
    void insertBefore(int key, int value) {
        int pos = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Value not found\n";
            return;
        }

        if (size == capacity) {
            resize();
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

    // Delete specific value
    void deleteValue(int key) {
        int pos = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Value not found\n";
            return;
        }

        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }
};

int main() {
    ArrayList list;
    int choice, value, key;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert End\n2. Insert Start\n3. Insert After\n4. Insert Before\n";
        cout << "5. Display\n6. Delete End\n7. Delete Start\n8. Delete Value\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertStart(value);
                break;

            case 3:
                cout << "Enter key and value: ";
                cin >> key >> value;
                list.insertAfter(key, value);
                break;

            case 4:
                cout << "Enter key and value: ";
                cin >> key >> value;
                list.insertBefore(key, value);
                break;

            case 5:
                list.display();
                break;

            case 6:
                list.deleteEnd();
                break;

            case 7:
                list.deleteStart();
                break;

            case 8:
                cout << "Enter value to delete: ";
                cin >> key;
                list.deleteValue(key);
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