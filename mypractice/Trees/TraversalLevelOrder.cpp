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

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* current = Q.front();   // ✔ front() not Front()
        Q.pop();                     // ✔ pop() must be called

        cout << current->data << " ";

        if (current->left != NULL)
            Q.push(current->left);   // ✔ pass node

        if (current->right != NULL)
            Q.push(current->right);  // ✔ pass node
    }
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    Node *temp= root->left;
    temp->left=new Node(40);
    temp->right=new Node(50);
     cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}