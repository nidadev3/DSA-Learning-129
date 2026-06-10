#ifndef AVLTREE_H
#define AVLTREE_H

#include "Student.h"

struct AVLNode {
    Student data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(Student s) : data(s), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;
    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insertHelper(AVLNode* node, Student s);
    void inorderHelper(AVLNode* node);
public:
    AVLTree();
    void insert(Student s);
    void inorder();
    AVLNode* search(AVLNode* node, float cgpa);
};

#endif