#include "../include/AVLTree.h"
#include <iostream>
using namespace std;

AVLTree::AVLTree() {
    root = nullptr;
}

int AVLTree::getHeight(AVLNode* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int AVLTree::getBalance(AVLNode* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

AVLNode* AVLTree::insertHelper(AVLNode* node, Student s) {
    if (node == nullptr) return new AVLNode(s);
    if (s.cgpa < node->data.cgpa) {
        node->left = insertHelper(node->left, s);
    } else if (s.cgpa > node->data.cgpa) {
        node->right = insertHelper(node->right, s);
    } else {
        return node;
    }
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && s.cgpa < node->left->data.cgpa)
        return rotateRight(node);
    if (balance < -1 && s.cgpa > node->right->data.cgpa)
        return rotateLeft(node);
    if (balance > 1 && s.cgpa > node->left->data.cgpa) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && s.cgpa < node->right->data.cgpa) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void AVLTree::inorderHelper(AVLNode* node) {
    if (node == nullptr) return;
    inorderHelper(node->left);
    cout << node->data.rollNo << " | "
         << node->data.name << " | "
         << node->data.cgpa << endl;
    inorderHelper(node->right);
}

void AVLTree::insert(Student s) {
    root = insertHelper(root, s);
}

void AVLTree::inorder() {
    inorderHelper(root);
}