#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertatstart(Node *&head,int value){
    Node* newnode=new Node();
    newnode->data=value;

    if(head==nullptr){
        newnode->next=newnode;
        head=newnode;
        return;
    }

    Node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }

    newnode->next=head;
    tail->next=newnode;
    head=newnode;
}

void insertatend(Node *&head,int value){
    Node* newnode=new Node();
    newnode->data=value;

    if(head==nullptr){
        newnode->next=newnode;
        head=newnode;
        return;
    }

    Node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }

    tail->next=newnode;
    newnode->next=head;
}

void insertatanypos(Node *&head,int value,int pos){

    if(pos==1){
        insertatstart(head,value);
        return;
    }

    Node* newnode=new Node();
    newnode->data=value;

    Node* temp=head;

    for(int i=1;i<pos-1 && temp->next!=head;i++){
        temp=temp->next;
    }

    newnode->next=temp->next;
    temp->next=newnode;
}

void display(Node* head){

    if(head==nullptr){
        cout<<"List is empty\n";
        return;
    }

    Node* temp=head;

    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);

    cout<<endl;
}

int main(){

    Node* head=nullptr;
    int n,value,pos;

    cout<<"Enter number of nodes to create: ";
    cin>>n;

    for(int i=1;i<=n;i++){
        cout<<"Enter value: ";
        cin>>value;
        insertatend(head,value);
    }

    cout<<"Circular Linked List: ";
    display(head);

    cout<<"Insert at start (enter value): ";
    cin>>value;
    insertatstart(head,value);
    display(head);

    cout<<"Insert at end (enter value): ";
    cin>>value;
    insertatend(head,value);
    display(head);

    cout<<"Insert at position\nEnter value and position: ";
    cin>>value>>pos;
    insertatanypos(head,value,pos);
    display(head);

    return 0;
}