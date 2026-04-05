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
        temp->next = head;
        return;
    }

    Node* ptr = head;
    while(ptr->next != head) {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->next = head;
}

void josephus(int k) {
    Node* ptr = head;

    while(ptr->next != ptr) {
        for(int i = 1; i < k - 1; i++) {
            ptr = ptr->next;
        }

        Node* temp = ptr->next;
        ptr->next = temp->next;

        if(temp == head)
            head = temp->next;

        delete temp;
        ptr = ptr->next;
    }

    cout << "Last remaining: " << ptr->data << endl;
}

int main() {

    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);

    josephus(3);

    return 0;
}
