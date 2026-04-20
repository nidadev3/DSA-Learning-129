#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Preorder Traversal: Root → Left → Right
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";  // visit root
    preorder(root->left);       // visit left subtree
    preorder(root->right);      // visit right subtree
}

int main() {

    // Creating tree
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    Node* temp = root->left;
    temp->left = new Node(4);
    temp->right = new Node(5);

    temp = root->right;
    temp->left = new Node(6);
    temp->right = new Node(7);

    // Output
    cout << "Preorder Traversal: ";
    preorder(root);

    return 0;
}