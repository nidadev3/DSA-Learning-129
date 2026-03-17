#include <iostream>
using namespace std;
struct Node{
    int data;
    Node * prev;
    Node * next;
};

//Creation
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


//Display

void display(Node* head){
    if(head == nullptr){
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "List is: ";

    do {
        cout << temp->data;
        temp = temp->next;
        if(temp != head) cout << "<->"; 
    } while(temp != head);

    cout << endl;
}

//insert at start 
void insertAtBeginning(Node*& head,int value)
{
    Node* newnode = new Node;
    newnode->data = value;

    if(head == nullptr)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    Node* last = head->prev;

    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;

    head = newnode;
}


//insertatend

void insertAtEnd(Node*& head,int value)
{
    Node* newnode = new Node;
    newnode->data = value;

    if(head == nullptr)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    Node* last = head->prev;

    last->next = newnode;
    newnode->prev = last;

    newnode->next = head;
    head->prev = newnode;
}
//insertatanypostion
void insertAtPosition(Node*& head, int pos, int value) {
    Node* newnode = new Node();
    newnode->data = value;

    if(head == nullptr) {  
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
        return;
    }

    
    if(pos == 1) {
        Node* last = head->prev;
        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
        head = newnode;
        return;
    }

    
    Node* temp = head;
    int count = 1;
    while(count < pos-1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    Node* last = temp->next;      

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = last;
    last->prev = newnode;

  
    if(temp == head->prev) {
        head->prev = newnode;
    }
}