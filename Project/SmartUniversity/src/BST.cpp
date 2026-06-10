#include "../include/BST.h"
#include <iostream>
using namespace std;

BST::BST() {
    root = nullptr;
}

BSTNode* BST::insertHelper(BSTNode* node, Student s) {
    if (node == nullptr) {
        return new BSTNode(s);
    }
    if (s.rollNo < node->data.rollNo) {
        node->left = insertHelper(node->left, s);
    } else if (s.rollNo > node->data.rollNo) {
        node->right = insertHelper(node->right, s);
    }
    return node;
}

BSTNode* BST::minNode(BSTNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BSTNode* BST::deleteHelper(BSTNode* node, int rollNo) {
    if (node == nullptr) return nullptr;
    if (rollNo < node->data.rollNo) {
        node->left = deleteHelper(node->left, rollNo);
    } else if (rollNo > node->data.rollNo) {
        node->right = deleteHelper(node->right, rollNo);
    } else {
        if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        BSTNode* temp = minNode(node->right);
        node->data = temp->data;
        node->right = deleteHelper(node->right, temp->data.rollNo);
    }
    return node;
}

BSTNode* BST::searchHelper(BSTNode* node, int rollNo) {
    if (node == nullptr || node->data.rollNo == rollNo) {
        return node;
    }
    if (rollNo < node->data.rollNo) {
        return searchHelper(node->left, rollNo);
    }
    return searchHelper(node->right, rollNo);
}

void BST::inorderHelper(BSTNode* node) {
    if (node == nullptr) return;
    inorderHelper(node->left);
    cout << node->data.rollNo << " | "
         << node->data.name << " | "
         << node->data.cgpa << endl;
    inorderHelper(node->right);
}

void BST::insert(Student s) {
    root = insertHelper(root, s);
}

void BST::remove(int rollNo) {
    root = deleteHelper(root, rollNo);
}

Student* BST::search(int rollNo) {
    BSTNode* result = searchHelper(root, rollNo);
    if (result != nullptr) return &result->data;
    return nullptr;
}

void BST::inorder() {
    inorderHelper(root);
}