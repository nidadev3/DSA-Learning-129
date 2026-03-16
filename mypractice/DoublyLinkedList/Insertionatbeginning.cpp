#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};

void printforward(Node *head){
    Node *ptr = head;

    while(ptr != nullptr){
        cout << ptr->data << " <-> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}


void insertatbeginning(Node *&head,int value){

    Node* newnode = new Node();
    newnode->data = value;
    newnode->prev = nullptr;
    newnode->next = head;

    if(head != nullptr){
        head->prev = newnode;
    }

    head = newnode;
}

int main(){

    Node *head = nullptr;

    insertatbeginning(head,10);
    insertatbeginning(head,20);
    insertatbeginning(head,30);

    cout<<"Forward Traversal:\n";
    printforward(head);

}