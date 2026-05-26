#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node* right;

    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

bool isless(Node * root , int value){

}

bool isgreat(Node * root , int value){

}

bool isBSTUtil(Node* root, int minValue, int maxValue){

    if(root==NULL){
        return true;
    }

    if(root->data > minValue && root->data < maxValue &&
       isBSTUtil(root->left, minValue, root->data) &&
       isBSTUtil(root->right, root->data, maxValue))
    {
        return true;
    }

    return false;
}

bool isBST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}