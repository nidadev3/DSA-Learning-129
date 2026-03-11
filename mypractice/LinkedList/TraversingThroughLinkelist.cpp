#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
int main (){
    Node*head=nullptr;
    Node* newnode=new Node();
    newnode->data=10;
    newnode->link=nullptr;
    head=newnode;
    Node* newnode1=new Node();
    newnode1->data=20;
    newnode1->link=nullptr;
    newnode->link=newnode1;

    Node* newnode2=new Node();
    newnode2->data=30;
    newnode1->link=newnode2;
    Node* temp=head;
    while(temp!=nullptr){
        cout<<"Node Data: "<<temp->data<<endl;
        temp=temp->link;
    }
}