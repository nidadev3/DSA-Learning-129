#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

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

void deletefromstart(Node* &head){

    if(head==nullptr){
        cout<<"List is empty\n";
        return;
    }

    if(head->next==head){
        delete head;
        head=nullptr;
        return;
    }

    Node* tail=head;

    while(tail->next!=head){
        tail=tail->next;
    }

    Node* temp=head;
    head=head->next;
    tail->next=head;

    delete temp;
}

void deletefromend(Node* &head){

    if(head==nullptr){
        cout<<"List is empty\n";
        return;
    }

    if(head->next==head){
        delete head;
        head=nullptr;
        return;
    }

    Node* temp=head;
    Node* prev=nullptr;

    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }

    prev->next=head;

    delete temp;
}

void deleteatpos(Node* &head,int pos){

    if(pos==1){
        deletefromstart(head);
        return;
    }

    Node* temp=head;
    Node* prev=nullptr;

    for(int i=1;i<pos;i++){
        prev=temp;
        temp=temp->next;

        if(temp==head){
            cout<<"Position out of range\n";
            return;
        }
    }

    prev->next=temp->next;

    delete temp;
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

    cout<<"Enter number of nodes: ";
    cin>>n;

    for(int i=1;i<=n;i++){
        cout<<"Enter value: ";
        cin>>value;
        insertatend(head,value);
    }

    cout<<"Original List: ";
    display(head);

    cout<<"After deleting from start: ";
    deletefromstart(head);
    display(head);

    cout<<"After deleting from end: ";
    deletefromend(head);
    display(head);

    cout<<"Enter position to delete: ";
    cin>>pos;

    deleteatpos(head,pos);

    cout<<"After deleting at position: ";
    display(head);

    return 0;
}