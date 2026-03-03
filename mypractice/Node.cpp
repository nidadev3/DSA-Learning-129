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
struct Node{
    int data;
    Node *next;
};
int main(){
    Node* node1=new Node();
    node1->data=10;
    node1->next=nullptr;
    cout<<"Node Data: "<<node1->data<<endl;
    cout<<"Address of Node: "<<node1<<endl;
    Node *head=node1;
    head->data=20;
    head->next=nullptr;

    cout<<"Node Data: "<<head->data<<endl;
    cout<<"Address of Node: "<<head<<endl;
    cout<<"Node Next: "<<head->next<<endl;
    delete node1;

    return 0;
}