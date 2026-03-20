#include<iostream>
using namespace std;

class stack {
private:
    int arr[100];
    int top;
    int capacity;

public:
    // Constructor
    stack(int capacity) {
        this->capacity = capacity;
        top = -1;
    }

    // Push function
    void push(int x) {
        if (top == capacity - 1) {
            cout << "The stack is overflow" << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack" << endl;
    }

    // Pop function
    int pop() {
        if (top == -1) {
            cout << "Underflow! Stack is empty." << endl;
            return -1;
        }
        return arr[top--];
    }

    // Peek function
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top is: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Empty? " << s.isEmpty() << endl;

    return 0;
}