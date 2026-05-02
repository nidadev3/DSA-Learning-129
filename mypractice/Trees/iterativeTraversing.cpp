#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
//preorder
void preOrder(Node* root){

}


//inorder
void inOrder(Node* root){

}


//postorder
void postOrder(Node* root){

}

int main (){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    //Traversal
    cout<<"PreOrder:";
    preOrder(root);

     cout<<"\nInOrder:";
     inOrder(root);

      cout<<"\nPostOrder:";
     postOrder(root);

     return 0;
}