#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // push
    void push(char x) {
        Node* newnode = new Node(x);
        newnode->next = top;
        top = newnode;
    }

    // isEmpty
    bool isEmpty() {
        return top == nullptr;
    }

    // pop
    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return '\0';
        }

        Node* temp = top;
        char value = temp->data;

        top = top->next;
        delete temp;

        return value;
    }
};

int main() {
    string st;
    cout << "Enter the string: ";
    cin >> st;

    Stack s;

    // push
    for (int i = 0; i < st.length(); i++) {
        s.push(st[i]);
    }

    // pop
    for (int i = 0; i < st.length(); i++) {
        st[i] = s.pop();
    }

    cout << "Reversed String: " << st << endl;

    return 0;
}