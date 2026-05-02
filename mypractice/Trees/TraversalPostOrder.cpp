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
//left,right,root
void postOrder(Node* root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    Node *temp= root->left;
    temp->left=new Node(40);
    temp->right=new Node(50);
     cout << "Post Order Traversal: ";
postOrder(root);

    return 0;
}