#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

Node* insert(Node* root,int value){

    if(root==NULL){
        return new Node(value);
    }

    if(value<root->data){
        root->left=insert(root->left,value);
    }

    else if(value>root->data){
        root->right=insert(root->right,value);
    }

    return root;
}

Node* minNodeRecursive(Node* root){

    if(root==NULL)
        return NULL;

    if(root->left==NULL)
        return root;

    return minNodeRecursive(root->left);
}

Node* maxNodeRecursive(Node* root){

    if(root==NULL)
        return NULL;

    if(root->right==NULL)
        return root;

    return maxNodeRecursive(root->right);
}

int main(){

    Node* root=NULL;

    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,80);

    Node* min=minNodeRecursive(root);
    Node* max=maxNodeRecursive(root);

    cout<<"Minimum Node: "<<min->data<<endl;
    cout<<"Maximum Node: "<<max->data<<endl;

    return 0;
}