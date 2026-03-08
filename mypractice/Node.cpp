#include<iostream>
using namespace std;

//Node in Stack
// struct Node{
//     int data;
//     Node *next;
// };
// int main (){
// Node Node1;
// Node1.data=10;
// Node1.next=nullptr;
// cout<<"Node Data: "<<Node1.data<<endl;
// cout<<"Address of Node: "<<&Node1<<endl;
// cout<<"Node Next: "<<Node1.next<<endl;
// return 0;
// }

//Node in Heap
// struct Node{
//     int data;
//     Node *next;
// };
// int main(){
//     Node *Node1=new Node();
//     Node1->data=10;
//     Node1->next=nullptr;
//     cout<<"Node Data: "<<Node1->data<<endl;
//     cout<<"Address of Node: "<<Node1<<endl;
//     cout<<"Node Next: "<<Node1->next<<endl;
//     delete Node1;
//     return 0;
// }

//Node with head pointer
// struct Node{
//     int data;
//     Node *next;
// };
// int main(){
//     Node* node1=new Node();
//     node1->data=10;
//     node1->next=nullptr;
//     cout<<"Node Data: "<<node1->data<<endl;
//     cout<<"Address of Node: "<<node1<<endl;
//     Node *head=node1;
//     head->data=20;
//     head->next=nullptr;

//     cout<<"Node Data: "<<head->data<<endl;
//     cout<<"Address of Node: "<<head<<endl;
//     cout<<"Node Next: "<<head->next<<endl;
//     delete node1;

//     return 0;
// }

//Creating linked list with 3 nodes


// struct Node {
//     int data;     
//     Node* next;   
// };

// int main() {
    
//     Node* node1 = new Node();
//     node1->data = 10;       
//     node1->next = nullptr; 

    
//     Node* head = node1;     

    
//     Node* node2 = new Node();
//     node2->data = 20;
//     node2->next = nullptr;  

   
//     node1->next = node2;

 
//     Node* node3 = new Node();
//     node3->data = 30;
//     node3->next = nullptr; 
    
//     node2->next = node3;

//     cout << "Node 1 Data: " << node1->data << endl;
//     cout << "Node 2 Data: " << node2->data << endl;
//     cout << "Node 3 Data: " << node3->data << endl;

//     cout << "Node 1 Address (head): " << head << endl;
//     cout << "Node 1 Next: " << node1->next << endl;
//     cout << "Node 2 Next: " << node2->next << endl;
//     cout << "Node 3 Next: " << node3->next << endl;

   
//     delete node3;
//     delete node2;
//     delete node1;

//     return 0;
// }

//Linked list with head
// struct Node {
//     int data;     
//     Node* next;   
// };
// int main (){
//     Node *head=new Node();
//     head->data=10;
//     head->next=nullptr;
    
//     head->next=new Node();
//     head->next->data=20;
//     head->next->next=nullptr;

//     head->next->next=new Node();
//     head->next->next->data=30;
//     head->next->next->next=nullptr;

//     cout<<"Node 1 Data: "<<head->data<<endl;
//     cout<<"Node 2 Data: "<<head->next->data<<endl;
//     cout<<"Node 3 Data: "<<head->next->next->data<<endl;
//     cout<<"Node 1 Address (head): "<<head<<endl;
//     cout<<"Node 1 Next: "<<head->next<<endl;
//     cout<<"Node 2 Next: "<<head->next->next<<endl;
//     cout<<"Node 3 Next: "<<head->next->next->next<<endl;
//     return 0;
// }


//Traversing through linked list
// struct Node{
// int data;
// Node*next;
// };
// int main(){
//     Node* head=new Node();
//     head->data=10;
//     head->next=nullptr;
//     head->next=new Node();
//     head->next->data=20;
//     head->next->next=nullptr;
//     head->next->next=new Node();
//     head->next->next->data=30;
//     head->next->next->next=nullptr;

//     Node* temp=head;
//     while(temp!=nullptr){
//         cout<<"Node Data: "<<temp->data<<endl;
//         temp=temp->next;
//     }
// }

// struct Node{
// int data;
// Node*next;
// };
// int countlist(Node* head){
//     int count=0;
//     Node* temp=head;
//     while(temp!=nullptr){
//         count++;
//         temp=temp->next;
//     }
//     return count;
//    }

// int main(){
//     Node* head=new Node();
//     head->data=10;
//     head->next=nullptr;
//     head->next=new Node();
//     head->next->data=20;
//     head->next->next=nullptr;
//     head->next->next=new Node();
//     head->next->next->data=30;
//     head->next->next->next=nullptr;

   
//    cout<<"Number of nodes in the linked list: "<<countlist(head)<<endl;}

// Searching for a value in the linked list
// struct Node{
//     int data;
//     Node*next;
// };
// bool search(Node*head, int value){
//     Node *temp=head;
//     while(temp!=nullptr){
//         if(temp->data==value){
//             return true;
//         }
//         temp=temp->next;
//     }
//     return false;
// }
// int main (){
//     Node* head=new Node();
//     head->data=10;
//     head->next=nullptr;
//     head->next=new Node();
//     head->next->data=20;
//     head->next->next=nullptr;
//     head->next->next=new Node();
//     head->next->next->data=30;
//     head->next->next->next=nullptr;

//     int valueToSearch;

//     cout<<"Enter the value to search in the linked list: ";
//     cin>>valueToSearch;
//     if(search(head, valueToSearch)){
//         cout<<"Value "<<valueToSearch<<" found in the linked list."<<endl;
//     } else {
//         cout<<"Value "<<valueToSearch<<" not found in the linked list."<<endl;
//     }
//     return 0;
// }

// Adding a new node at the beginning of the linked list
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// Node* addAtBeginning(Node* head, int value) {
//     Node* newNode = new Node();
//     newNode->data = value;
//     newNode->next = head;
//     head = newNode;
//     return head;
// }

// int main() {
//     Node* head = nullptr;

  
//     head = addAtBeginning(head, 10);
//     head = addAtBeginning(head, 20);
//     head = addAtBeginning(head, 30);

    
//     cout << "Linked list: " << endl;
//     Node* temp = head;
//     while(temp != nullptr) {
//         cout << "Node Data: " << temp->data << endl;
//         temp = temp->next;
//     }

//     return 0;
// }

//Adding node at the end of the linked list
struct Node {
    int data;
    Node* next;
};
Node* addAtEnd(Node* head, int value){
    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=nullptr;
    if(head==nullptr){
        head=newNode;
        return head;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
int main(){
    Node* head=nullptr;
    head=addAtEnd(head, 10);
    head=addAtEnd(head, 20);
    head=addAtEnd(head, 30);
    cout<<"Linked list: "<<endl;
    Node* temp=head;
    while(temp!=nullptr){
        cout<<"Node Data: "<<temp->data<<endl;
        temp=temp->next;
    }
}