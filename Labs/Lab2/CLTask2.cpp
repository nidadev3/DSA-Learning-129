#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertEnd(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    if(head == NULL) {
        head = temp;
        return;
    }

    Node* ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;
}

void display() {
    Node* ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

Node* search(int value) {
    Node* ptr = head;
    while(ptr != NULL) {
        if(ptr->data == value) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void swapNodes(int x, int y) {
    if(x == y) return;

    Node* node1 = search(x);
    Node* node2 = search(y);

    if(node1 == NULL || node2 == NULL) return;

    if(node1->prev) node1->prev->next = node2;
    else head = node2;

    if(node2->prev) node2->prev->next = node1;
    else head = node1;

    if(node1->next) node1->next->prev = node2;
    if(node2->next) node2->next->prev = node1;

    swap(node1->prev, node2->prev);
    swap(node1->next, node2->next);
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();

    swapNodes(20, 40);

    display();

    return 0;
}