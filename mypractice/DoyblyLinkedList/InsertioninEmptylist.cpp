#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* pre;
    Node* next;
};
void printforward(Node* &head){
    Node* ptr=head;
    while(ptr!=nullptr){
         cout << ptr->data << " <-> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}
void printbackward(Node* &head){
    Node* ptr=head;
    while(ptr!=nullptr){
         cout << ptr->data << " <-> ";
        ptr = ptr->pre;
    }
    cout << "NULL\n";
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    int n;
    cout<<"Enter the number of node:";
    cin>>n;
    for(int i=0;i<n;i++){
        Node* newnode=new Node();
        cout<<"Enter the data for node"<<i+1<<":";
        cin>>newnode->data;
         newnode->pre = nullptr;
        newnode->next = nullptr;
        if(head==nullptr){
             head = newnode;
            tail = newnode;
        }
        else{
            newnode->pre= tail;
            tail->next = newnode;
            tail = newnode;

        }

    }
     cout << "Doubly Linked List (Forward): ";
    printforward(head);

    cout << "Doubly Linked List (Backward): ";
    printbackward(tail);

    return 0;
}