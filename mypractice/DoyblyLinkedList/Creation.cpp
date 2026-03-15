#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* pre;
    Node* next;
};

int main(){

    // First Node
    Node *newnode = new Node();
    newnode->pre = nullptr;
    newnode->data = 15;
    newnode->next = nullptr;

    Node *head = nullptr;
    head = newnode;

    // Second Node
    Node *node2 = new Node();
    node2->data = 25;
    node2->next = nullptr;
    node2->pre = newnode;

    newnode->next = node2;

    // Third Node
    Node *node3 = new Node();
    node3->data = 35;
    node3->next = nullptr;
    node3->pre = node2;

    node2->next = node3;

    // Printing nodes
    Node *temp = head;

    while(temp != nullptr){
        cout << "Previous: " << temp->pre << endl;
        cout << "Data: " << temp->data << endl;
        cout << "Next: " << temp->next << endl;
        cout << "------------------" << endl;

        temp = temp->next;
    }

}