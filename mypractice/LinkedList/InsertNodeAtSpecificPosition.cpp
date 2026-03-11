#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
void insertatPosition(Node* &head,int value,int position){
    Node* newnode=new Node();
    newnode->data=value;
    if(position==1){
        newnode->link=head;
        head=newnode;
      return;
    }
    
    Node* temp=head;
    for(int i=1;i<position-1 && temp!=nullptr;i++){
        temp=temp->link;
    }
    if(temp==nullptr){
        cout<<"Position out of bounds"<<endl;
      return;
    }
    newnode->link=temp->link;
    temp->link=newnode;
   
}
int main (){
    Node* head=nullptr;
    insertatPosition(head,10,1);
   insertatPosition(head,20,2);
    insertatPosition(head,30,3);
    insertatPosition(head,25,2);
    Node* temp=head;
    while(temp!=nullptr){
        cout<<"Node Data: "<<temp->data<<endl;
        temp=temp->link;
    }
}