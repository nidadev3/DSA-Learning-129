#include<iostream>
using namespace std;

class stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }

    bool isFull() {
        if (top == capacity - 1) {
           0 cout << "Stack is overflow" << endl;
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return true;
        }
        return false;
    }

    void push(int value) {
        if (isFull()) return;
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) return -1;
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }

    void display() {
        if (isEmpty()) return;

        cout << "Stack elements:\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    int choice, data;

    cout << "Enter the capacity of stack: ";
    cin >> data;

    stack s(data);

    while (1) {
        cout << "\n1- Push\n";
        cout << "2- Pop\n";
        cout << "3- Peek (Top)\n";
        cout << "4- Display\n";
        cout << "5- Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "How many elements you want to push? ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                if (s.isFull()) break;

                int val;
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
            }
        }
        else if (choice == 2) {
            int val = s.pop();
            if (val != -1)
                cout << "Popped: " << val << endl;
        }
        else if (choice == 3) {
            int val = s.peek();
            if (val != -1)
                cout << "Top element: " << val << endl;
        }
        else if (choice == 4) {
            s.display();
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}