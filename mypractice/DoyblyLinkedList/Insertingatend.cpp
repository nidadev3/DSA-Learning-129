#include<iostream>
using namespace std;

struct Node{
    int data; 
    Node *next;
    Node *prev;
};

void printforward(Node *head){
    Node *ptr=head;

    while(ptr!=nullptr){
        cout<<ptr->data<<" <-> ";
        ptr=ptr->next;
    }

    cout<<"NULL\n";
}

void insertatend(Node*& head,int value){

    Node *newnode=new Node();
    newnode->data=value;
    newnode->next=nullptr;
    newnode->prev=nullptr;

    if(head==nullptr){
        head=newnode;
        return;
    }

    Node* temp=head;

    while(temp->next!=nullptr){
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->prev=temp;
}

int main(){

    Node* head=nullptr;

    insertatend(head,10);
    insertatend(head,20);
    insertatend(head,30);

    printforward(head);

}