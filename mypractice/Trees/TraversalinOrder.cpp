#include<iostream>
#include<queue>
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
//left,root,right
void inOrder(Node* root) {
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    Node *temp= root->left;
    temp->left=new Node(40);
    temp->right=new Node(50);
     cout << "InOrder Traversal: ";
inOrder(root);

    return 0;
}