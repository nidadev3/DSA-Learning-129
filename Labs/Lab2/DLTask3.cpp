#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

Node* head = NULL;
DNode* dhead = NULL;

void insertSLL(int value) {
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

void displaySLL() {
    Node* ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void insertDLL(int value) {
    DNode* temp = new DNode();
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    if(dhead == NULL) {
        dhead = temp;
        return;
    }

    DNode* ptr = dhead;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;
}

void convertToDLL() {
    Node* ptr = head;

    while(ptr != NULL) {
        insertDLL(ptr->data);
        ptr = ptr->next;
    }
}

void displayDLL() {
    DNode* ptr = dhead;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {

    insertSLL(10);
    insertSLL(20);
    insertSLL(30);

    displaySLL();

    convertToDLL();

    displayDLL();

    return 0;
}