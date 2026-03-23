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

    void push(int x) {
        Node* newnode = new Node(x);
        newnode->link = top;
        top = newnode;

        cout << x << " pushed into the stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        cout << top->data << " is popped\n";

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

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.pop();
    s.display();

    s.pop();
    s.pop();

    s.pop(); // underflow test

    return 0;
}