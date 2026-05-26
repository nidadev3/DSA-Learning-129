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

    return false;
}

Node* minNode(Node* root){
    while(root->left!=NULL)
        root=root->left;

    return root;
}

Node* deleteNode(Node* root, int value){

    if(root==NULL)
        return NULL;

    if(value<root->data){
        root->left=deleteNode(root->left,value);
    }

    else if(value>root->data){
        root->right=deleteNode(root->right,value);
    }

    else{

        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        Node* temp=minNode(root->right);

        root->data=temp->data;

        root->right=deleteNode(root->right,temp->data);
    }

    return root;
}

void inorder(Node* root){
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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

    cout<<"Inorder before deletion: ";
    inorder(root);

    cout<<"\n";

    if(search(root,40))
        cout<<"40 found\n";
    else
        cout<<"40 not found\n";

    root=deleteNode(root,20);

    if(search(root,20))
        cout<<"20 found\n";
    else
        cout<<"20 deleted successfully\n";

    cout<<"Inorder after deletion: ";
    inorder(root);

    cout<<"\n";

    return 0;
}
