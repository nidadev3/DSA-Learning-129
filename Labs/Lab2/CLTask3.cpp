#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;

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

void display() {
    Node* ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void deleteEvenPositions() {
    Node* curr = head;
    Node* prev = NULL;
    int pos = 1;

    while(curr != NULL) {
        if(pos % 2 == 0) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
        pos++;
    }
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    display();

    deleteEvenPositions();

    display();

    return 0;
}