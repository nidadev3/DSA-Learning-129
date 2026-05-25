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
 //search
 bool search(Node*root,int value){
    if (root==NULL){
        return false;
    }
    else if(root->data==value){
        return true;
    }
     else if(value<root->data){
        return search(root->left,value);
   }
   else if(value>root->data){
    return search(root->right,value);
   }
   retun false;
 }

 //delete
 Node* minNode(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int value) {

    if (root == NULL)
        return NULL;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }

    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }

    else {
        // NODE FOUND!

        // Case 1: No children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: One child

        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = minNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right,
                                 temp->data);
    }

    return root;
}