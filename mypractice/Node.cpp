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
#include <iostream>
using namespace std;


struct Node {
    int data;     
    Node* next;   
};

int main() {
    
    Node* node1 = new Node();
    node1->data = 10;       
    node1->next = nullptr; 

    
    Node* head = node1;     

    
    Node* node2 = new Node();
    node2->data = 20;
    node2->next = nullptr;  

   
    node1->next = node2;

 
    Node* node3 = new Node();
    node3->data = 30;
    node3->next = nullptr; 
    
    node2->next = node3;

    cout << "Node 1 Data: " << node1->data << endl;
    cout << "Node 2 Data: " << node2->data << endl;
    cout << "Node 3 Data: " << node3->data << endl;

    cout << "Node 1 Address (head): " << head << endl;
    cout << "Node 1 Next: " << node1->next << endl;
    cout << "Node 2 Next: " << node2->next << endl;
    cout << "Node 3 Next: " << node3->next << endl;

   
    delete node3;
    delete node2;
    delete node1;

    return 0;
}
