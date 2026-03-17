#include <iostream>
using namespace std;
struct Node{
    int data;
    Node * prev;
    Node * next;
};
void creation(Node *&head){
    int n;
    cout<<"Enter the number of nodes you want in the list:";
    cin>>n;
    Node* temp=nullptr;
    for(int i=0;i<n;i++){
    Node *newnode=new Node();
  cout<<"Enter data for node"<<i+1<<":";
  cin>>newnode->data;
  if(head==nullptr){
       head=newnode;
    newnode->prev=head;
    newnode->next=head;
    temp=head;
  }
    
    else{
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=head;
        head->prev=newnode;
        temp=newnode;
    }
    }

}