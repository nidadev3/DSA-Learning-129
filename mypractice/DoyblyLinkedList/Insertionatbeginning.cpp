#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
}
void printforward( Node *&head){
    Node *ptr=head;
    if(ptr!=nullptr){
        cout<<ptr->data<<"<->";
        ptr=ptr->link;
    }
    cout << "NULL\n";
}

void printbackward( Node *&head){
    Node *ptr=head;
    if(ptr!=nullptr){
        cout<<ptr->data<<"<->";
        ptr=ptr->prev;
    }
    cout << "NULL\n";
}
