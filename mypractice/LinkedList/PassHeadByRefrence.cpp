#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
void *addatBeginning(Node* &head,int value){
    Node* newnode=new Node();
    newnode->data=value;
    newnode->link=head;
    head=newnode;

}
int main (){
    Node* head=nullptr;
    addatBeginning(head,10);
   addatBeginning(head,20);
    addatBeginning(head,30);
    Node* temp=head;
    while(temp!=nullptr){
        cout<<"Node Data: "<<temp->data<<endl;
        temp=temp->link;
    }
}