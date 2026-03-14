#include<iostream>
using namespace std;
struct Node{
    Node *pre;
    int data;
    Node *next;
};
int main(){
    Node *newnode=new Node();
    newnode->pre=nullptr;
    newnode->data=15;
    newnode->next=nullptr;
    cout<<newnode->pre<<endl;
    cout<<newnode->data<<endl;
    cout<<newnode->next<<endl;
    
}