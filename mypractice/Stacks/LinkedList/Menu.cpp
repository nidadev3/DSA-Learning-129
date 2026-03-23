#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;

    Node(int data) {
        this->data = data;
        link = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newnode = new Node(value);
        newnode->link = top;
        top = newnode;

        cout << value << " pushed into the stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        cout << top->data << " popped\n";

        top = top->link;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << top->data << " is the top value\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        cout << "Stack elements: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->link;
        }

        cout << endl;
    }
};

int main() {
    Stack s;

    int choice, value;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}