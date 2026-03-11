#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
Node *deleteatend(Node* head){
    if (head==nullptr){
        cout<<"The linked list is empty"<<endl;
        return head;
    }
    if(head->link==nullptr){
        delete head;
        return nullptr;
    }
    // else{
    //     Node *temp=head;
    //     Node* temp2=head;
    //     while(temp->link!=nullptr){
    //         temp2=temp;
    //         temp=temp->link;
    //     }
    //     temp2->link=nullptr;
    //     delete temp;
    //     temp=nullptr;
    //     return head;
    // }
    else{
        Node* temp=head;
        while(temp->link->link!=nullptr){
            temp=temp->link;
        }
       delete temp->link;
        temp->link=nullptr;
        return head;
    }
}
int main(){
    Node* head=nullptr;
    // Creating a linked list with some nodes
    head=new Node();
    head->data=10;
    head->link=new Node();
    head->link->data=20;
    head->link->link=new Node();
    head->link->link->data=30;
    head->link->link->link=nullptr;

    cout<<"Original List: ";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;

   head= deleteatend(head);

    cout<<"List after deleting end node: ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}