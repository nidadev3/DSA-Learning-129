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

void findOccurrences(int value) {
    Node* ptr = head;
    int index = 0;

    while(ptr != NULL) {
        if(ptr->data == value) {
            cout << "Found at index: " << index << endl;
        }
        ptr = ptr->next;
        index++;
    }
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(10);
    insertEnd(30);
    insertEnd(10);

    display();

    findOccurrences(10);

    return 0;
}