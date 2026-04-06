#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to reverse linked list recursively
Node* reverseList(Node* head) {
    // Base case
    if (head == NULL || head->next == NULL)
        return head;

    // Recursive call
    Node* newHead = reverseList(head->next);

    // Reverse the link
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// Function to insert at end
Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = NULL;

    // Creating list: 1 → 2 → 3 → 4
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);

    cout << "Original List: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}