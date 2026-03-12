#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
Node *reverseList(Node* head){
    Node* prev=nullptr;
    Node* current=head;
    Node* next=nullptr;
    while(current!=nullptr){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}
int main (){
    Node* head=nullptr;
    // Creating a linked list with some nodes
    head=new Node();
    head->data=10;
    head->link=new Node();
    head->link->data=20;
    head->link->link=new Node();
    head->link->link->data=30;
    head->link->link->link=nullptr;

    cout<<"Original List: ";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;

   head= reverseList(head);

    cout<<"Reversed List: ";
     temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
     cout<<endl;    
}