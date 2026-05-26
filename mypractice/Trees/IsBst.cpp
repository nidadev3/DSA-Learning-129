#include<iostream>
#include<climits>
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
Node* insert(Node* root, int value){

    if(root==NULL){
        return new Node(value);
    }

    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }

    return root;
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
int main(){

    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    if(isBST(root))
        cout << "Tree is BST" << endl;
    else
        cout << "Tree is NOT BST" << endl;

    return 0;
}