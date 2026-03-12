#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *link;
};
void deletelist(Node *&head){
    Node *temp=head;
    while(temp!=nullptr){
        Node *nextnode=temp->link;
        delete temp;
        temp=nextnode;

    }
    head=nullptr;
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

   deletelist(head);

    cout<<"List after deleting all nodes: ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
     cout<<endl;
}
