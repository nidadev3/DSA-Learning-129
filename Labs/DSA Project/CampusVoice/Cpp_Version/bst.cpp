#include <iostream>
#include "BST.h"
 
using namespace std;
 
// Constructor
BST::BST() {
    root = NULL;
}
 
// ==================== INSERT ====================
BSTNode* BST::insertHelper(BSTNode* node, Complaint c) {
    if (node == NULL) {
        BSTNode* newNode = new BSTNode;
        newNode->data  = c;
        newNode->left  = NULL;
        newNode->right = NULL;
        return newNode;
    }
 
    if (c.id < node->data.id)
        node->left = insertHelper(node->left, c);
    else if (c.id > node->data.id)
        node->right = insertHelper(node->right, c);
    else
        cout << "Complaint ID already exists in BST!\n";
 
    return node;
}
 
void BST::insert(Complaint c) {
    root = insertHelper(root, c);
    cout << "Complaint ID " << c.id << " inserted into BST!\n";
}
 
// ==================== SEARCH ====================
Complaint BST::search(int id) {
    BSTNode* current = root;
 
    while (current != NULL) {
        if (id == current->data.id) {
            cout << "\nComplaint Found!\n";
            cout << "ID: "       << current->data.id          << endl;
            cout << "Name: "     << current->data.studentName  << endl;
            cout << "Category: " << current->data.category     << endl;
            cout << "Status: "   << current->data.status       << endl;
            cout << "Urgent: "   << (current->data.isUrgent ? "Yes" : "No") << endl;
            return current->data;
        }
        else if (id < current->data.id)
            current = current->left;
        else
            current = current->right;
    }
 
    cout << "Complaint ID " << id << " not found!\n";
    Complaint empty;
    empty.id = -1;
    return empty;
}
 
// ==================== DELETE ====================
BSTNode* BST::findMin(BSTNode* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}
 
BSTNode* BST::deleteHelper(BSTNode* node, int id) {
    if (node == NULL) {
        cout << "Complaint ID " << id << " not found!\n";
        return NULL;
    }
 
    if (id < node->data.id)
        node->left = deleteHelper(node->left, id);
    else if (id > node->data.id)
        node->right = deleteHelper(node->right, id);
    else {
        // Case 1: No children
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        }
        // Case 2: One child
        else if (node->left == NULL) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Two children — replace with inorder successor
        else {
            BSTNode* successor = findMin(node->right);
            node->data = successor->data;
            node->right = deleteHelper(node->right, successor->data.id);
        }
    }
    return node;
}
 
void BST::deleteNode(int id) {
    root = deleteHelper(root, id);
    cout << "Complaint ID " << id << " deleted from BST!\n";
}
 
// ==================== TRAVERSALS ====================
void BST::inorderHelper(BSTNode* node) {
    if (node == NULL) return;
    inorderHelper(node->left);
    cout << "ID: " << node->data.id << " | " << node->data.studentName
         << " | " << node->data.category << " | " << node->data.status << endl;
    inorderHelper(node->right);
}
 
void BST::preorderHelper(BSTNode* node) {
    if (node == NULL) return;
    cout << "ID: " << node->data.id << " | " << node->data.studentName
         << " | " << node->data.category << " | " << node->data.status << endl;
    preorderHelper(node->left);
    preorderHelper(node->right);
}
 
void BST::postorderHelper(BSTNode* node) {
    if (node == NULL) return;
    postorderHelper(node->left);
    postorderHelper(node->right);
    cout << "ID: " << node->data.id << " | " << node->data.studentName
         << " | " << node->data.category << " | " << node->data.status << endl;
}
 
void BST::inorder() {
    cout << "\n--- Inorder Traversal (Sorted by ID) ---\n";
    inorderHelper(root);
}
 
void BST::preorder() {
    cout << "\n--- Preorder Traversal ---\n";
    preorderHelper(root);
}
 
void BST::postorder() {
    cout << "\n--- Postorder Traversal ---\n";
    postorderHelper(root);
}
 
void BST::traversalMenu() {
    int choice;
    cout << "\n===== BST TRAVERSALS =====\n";
    cout << "1. Inorder   (Left → Root → Right)\n";
    cout << "2. Preorder  (Root → Left → Right)\n";
    cout << "3. Postorder (Left → Right → Root)\n";
    cout << "Enter choice: ";
    cin >> choice;
 
    if      (choice == 1) inorder();
    else if (choice == 2) preorder();
    else if (choice == 3) postorder();
    else cout << "Invalid choice!\n";
}