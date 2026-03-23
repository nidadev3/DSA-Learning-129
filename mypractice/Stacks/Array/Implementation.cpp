#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;        // pointer to our array
    int  top;        // index of top element
    int  capacity;   // max number of elements

public:

    // Constructor — create stack of given size
    Stack(int size) {
        capacity = size;
        arr      = new int[capacity];  // allocate memory
        top      = -1;                 // empty stack
    }

    // Destructor — free memory when done
    ~Stack() {
        delete[] arr;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Push — add item on top
    void push(int x) {
        if (isFull()) {
            cout << "Overflow! Stack is full.\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed.\n";
    }

    // Pop — remove and return top item
    int pop() {
        if (isEmpty()) {
            cout << "Underflow! Stack is empty.\n";
            return -1;
        }
        return arr[top--];
    }

    // Peek — see top without removing
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    // Size — how many items currently in stack
    int size() {
        return top + 1;
    }

    // Display — print all items top to bottom
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Peek: "  << s.peek() << "\n";
    cout << "Pop:  "  << s.pop()  << "\n";
    cout << "Size: "  << s.size() << "\n";
    s.display();

    return 0;
}