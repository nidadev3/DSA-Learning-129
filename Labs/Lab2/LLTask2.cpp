#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void insertEnd(Node*& head, int value) {
    Node* temp = createNode(value);

    if(head == NULL) {
        head = temp;
        return;
    }

    Node* ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void display(Node* head) {
    Node* ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

Node* mergeLists(Node* head1, Node* head2) {
    Node* newHead = NULL;

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1 != NULL) {
        insertEnd(newHead, ptr1->data);
        ptr1 = ptr1->next;
    }

    while(ptr2 != NULL) {
        insertEnd(newHead, ptr2->data);
        ptr2 = ptr2->next;
    }

    return newHead;
}

int main() {

    Node* head1 = NULL;
    Node* head2 = NULL;

    insertEnd(head1, 1);
    insertEnd(head1, 2);
    insertEnd(head1, 3);

    insertEnd(head2, 4);
    insertEnd(head2, 5);

    Node* merged = mergeLists(head1, head2);

    display(merged);

    return 0;
}