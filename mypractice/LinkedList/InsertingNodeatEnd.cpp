#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
Node* AddatEnd(Node* head, int value){
    Node* newnode=new Node();
    newnode->data= value;
    newnode -> link=nullptr;
  if(head==nullptr){
    head=newnode;
    return head;
  }
    Node* temp=head;
  while(temp->link!=nullptr){
    temp=temp->link;
  }
    temp->link=newnode;
    return head;
}
int main(){
    Node* head=nullptr;
    head=AddatEnd(head,10);
    head=AddatEnd(head,20);
    head=AddatEnd(head,30);
    Node* temp=head;
    while(temp!=nullptr){
        cout<<"Node Data: "<<temp->data<<endl;
        temp=temp->link;
    }
}                                                       