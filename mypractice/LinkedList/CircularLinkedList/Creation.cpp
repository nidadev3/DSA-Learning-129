#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
};
void create( Node* &head, Node *&tail){
    head=nullptr;
    tail=nullptr;
    int n;
cout<<"Enter the number of nodes:";
cin>>n;
for (int i=0;i<n;i++){
    Node* newnode=new Node();
    cout<<"Enter the value for the node"<<i+1<<":";
    cin>>newnode->data;
newnode->next=nullptr;
if(head==nullptr){
    head=newnode;
    tail=newnode;
    tail->next=head;
}
  tail->next = newnode;
  tail = newnode;
  tail->next = head;

}
}

void print(Node* head){
    if(!head) {
        cout<<"List is empty.";
    }

    Node* temp = head;

    while(true){
        cout << temp->data << " ";
        temp = temp->next;
        if(temp == head) break;  
    }

    cout << "\n";
}

   int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    create(head, tail);
    cout << "Circular Linked List: ";
    print(head);
}
