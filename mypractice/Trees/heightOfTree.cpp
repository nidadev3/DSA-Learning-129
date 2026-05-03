#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
//hEIGHT FUNCTION
int height(Node* root){
    if(root==NULL){
        return -1;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);


    return 1+max(leftHeight,rightHeight);
}
Node* createTree() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(2);
    root->left->right = new Node(7);

    return root;
}

int main() {
    Node* root = createTree();

    cout << "Height of tree: " << height(root) << endl;

    return 0;
}