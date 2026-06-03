#include <iostream>
#include "AVLTree.h"
 
using namespace std;
 
// Constructor
AVLTree::AVLTree() {
    root = NULL;
}
 
// ==================== HEIGHT ====================
int AVLTree::height(AVLNode* node) {
    if (node == NULL) return 0;
    return node->height;
}
 
// ==================== BALANCE FACTOR ====================
int AVLTree::getBalance(AVLNode* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}
 
// ==================== ROTATIONS ====================
// Right Rotate (for Left-Left case)
AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x  = y->left;
    AVLNode* T2 = x->right;
 
    x->right = y;
    y->left  = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}
 
// Left Rotate (for Right-Right case)
AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y  = x->right;
    AVLNode* T2 = y->left;
 
    y->left  = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
 
    return y;
}
 
// ==================== INSERT ====================
AVLNode* AVLTree::insertHelper(AVLNode* node, Complaint c) {
    // Normal BST insert
    if (node == NULL) {
        AVLNode* newNode = new AVLNode;
        newNode->data   = c;
        newNode->left   = NULL;
        newNode->right  = NULL;
        newNode->height = 1;
        return newNode;
    }
 
    if (c.id < node->data.id)
        node->left = insertHelper(node->left, c);
    else if (c.id > node->data.id)
        node->right = insertHelper(node->right, c);
    else {
        cout << "Duplicate ID in AVL Tree!\n";
        return node;
    }
 
    // Update height
    node->height = max(height(node->left), height(node->right)) + 1;
 
    // Check balance
    int balance = getBalance(node);
 
    // Left-Left Case
    if (balance > 1 && c.id < node->left->data.id)
        return rightRotate(node);
 
    // Right-Right Case
    if (balance < -1 && c.id > node->right->data.id)
        return leftRotate(node);
 
    // Left-Right Case
    if (balance > 1 && c.id > node->left->data.id) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right-Left Case
    if (balance < -1 && c.id < node->right->data.id) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}
 
void AVLTree::insert(Complaint c) {
    root = insertHelper(root, c);
    cout << "Complaint ID " << c.id << " inserted into AVL Tree!\n";
}
 
// ==================== SEARCH ====================
Complaint AVLTree::search(int id) {
    AVLNode* current = root;
 
    while (current != NULL) {
        if (id == current->data.id) {
            cout << "\nComplaint Found in AVL Tree!\n";
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
 
    cout << "Complaint ID " << id << " not found in AVL Tree!\n";
    Complaint empty;
    empty.id = -1;
    return empty;
}
 
// ==================== DELETE ====================
AVLNode* AVLTree::findMin(AVLNode* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}
 
AVLNode* AVLTree::deleteHelper(AVLNode* node, int id) {
    if (node == NULL) return NULL;
 
    if (id < node->data.id)
        node->left = deleteHelper(node->left, id);
    else if (id > node->data.id)
        node->right = deleteHelper(node->right, id);
    else {
        // Node found
        if (node->left == NULL || node->right == NULL) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (temp == NULL) {
                delete node;
                return NULL;
            } else {
                *node = *temp;
                delete temp;
            }
        } else {
            AVLNode* successor = findMin(node->right);
            node->data = successor->data;
            node->right = deleteHelper(node->right, successor->data.id);
        }
    }
 
    // Update height
    node->height = max(height(node->left), height(node->right)) + 1;
 
    // Rebalance
    int balance = getBalance(node);
 
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
 
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
 
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}
 
void AVLTree::deleteNode(int id) {
    root = deleteHelper(root, id);
    cout << "Complaint ID " << id << " deleted from AVL Tree!\n";
}
 
// ==================== INORDER ====================
void AVLTree::inorderHelper(AVLNode* node) {
    if (node == NULL) return;
    inorderHelper(node->left);
    cout << "ID: " << node->data.id << " | " << node->data.studentName
         << " | " << node->data.category << " | " << node->data.status
         << " | Height: " << node->height << endl;
    inorderHelper(node->right);
}
 
void AVLTree::inorder() {
    cout << "\n--- AVL Tree Inorder (Balanced, Sorted by ID) ---\n";
    inorderHelper(root);
}