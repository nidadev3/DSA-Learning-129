#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node* right;
    Node(int value){
    data=value;
    left=NULL;
    righT=NULL;
}
};

//insert
Node* insert(Node*root, int value){
    if (root==NULL){
        Node* newNode=new Node(value);
        return newNode;
    }
    else if(value<root->data){
        root->left=insert(root->left,value);
   }
   else if(value>root->data){
    root->right=insert(root->right,value);
   }
   return root;
}
 