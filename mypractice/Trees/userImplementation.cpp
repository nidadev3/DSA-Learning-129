#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node (int val){
        data=val;
        left=NULL;
        right=NULL; 
    }
};
//Function to create tree
Node* createTree(){
    int value;
    cout<<"Enter value(-1 for no node):";
    cin>>value;

    //Base condition
    if(value==-1){
        return NULL;
    }
    //create node
    Node* root=new Node(value);
    cout<<"Enter left child of"<<value<<endl;
    root->left=createTree();
    cout<<"Enter right child of"<<value<<endl;
    root->right=createTree();
    return root;
}