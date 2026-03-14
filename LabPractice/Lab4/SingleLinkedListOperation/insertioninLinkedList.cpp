#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};


void creation(Node* &head) {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of nodes must be at least 1." << endl;
        return;
    }

    Node* temp = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newnode = new Node();
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> newnode->data;
        newnode->link = nullptr;

        if (head == nullptr) {
            head = newnode;
            temp = newnode;
        } 
        else {
            temp->link = newnode;
            temp = newnode;
        }
    }
}


void printList(Node* head) {
    Node* ptr = head;

    while (ptr != nullptr) {
        cout << ptr->data;
        if (ptr->link != nullptr) {
            cout << " -> ";
        }
        ptr = ptr->link;
    }

    cout << " -> NULL" << endl;
}


void insertAtHead(Node* &head, int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->link = head;
    head = newnode;

    cout << "Node inserted at head." << endl;
}

void insertAtEnd(Node* &head, int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->link = nullptr;

    if (head == nullptr) {
        head = newnode;
        cout << "Node inserted at end." << endl;
        return;
    }

    Node* temp = head;
    while (temp->link != nullptr) {
        temp = temp->link;
    }

    temp->link = newnode;
    cout << "Node inserted at end." << endl;
}


void insertAtPosition(Node* &head, int value, int pos) {
    if (pos <= 0) {
        cout << "Invalid position." << endl;
        return;
    }

    if (pos == 1) {
        insertAtHead(head, value);
        return;
    }

    Node* newnode = new Node();
    newnode->data = value;

    Node* temp = head;

    for (int i = 1; i < pos - 1; i++) {
        if (temp == nullptr) {
            cout << "Position out of range." << endl;
            delete newnode;
            return;
        }
        temp = temp->link;
    }

    if (temp == nullptr) {
        cout << "Position out of range." << endl;
        delete newnode;
        return;
    }

    newnode->link = temp->link;
    temp->link = newnode;

    cout << "Node inserted at position " << pos << "." << endl;
}


int main() {
    Node* head = nullptr;

    creation(head);
    printList(head);

    int value;

    cout << "Enter value to insert at head: ";
    cin >> value;
    insertAtHead(head, value);
    printList(head);

    cout << "Enter value to insert at end: ";
    cin >> value;
    insertAtEnd(head, value);
    printList(head);

    int pos;
    cout << "Enter value to insert at any position: ";
    cin >> value;
    cout << "Enter position: ";
    cin >> pos;
    insertAtPosition(head, value, pos);
    printList(head);

    return 0;
}