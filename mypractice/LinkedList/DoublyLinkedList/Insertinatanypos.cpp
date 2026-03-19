#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;


void insertAtPosition(int value, int pos) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if(pos <= 1 || head == NULL) { 
        newNode->next = head;
        if(head) head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    for(int i = 1; i < pos-1 && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}


void display() {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insertAtPosition(10, 1); 
    insertAtPosition(20, 2); 
    insertAtPosition(5, 1);  
    insertAtPosition(15, 3); 

    display(); // Output: 5 10 15 20

    return 0;
}