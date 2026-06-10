#ifndef BST_H
#define BST_H

#include "Student.h"

struct BSTNode {
    Student data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Student s) : data(s), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode* root;
    BSTNode* insertHelper(BSTNode* node, Student s);
    BSTNode* deleteHelper(BSTNode* node, int rollNo);
    BSTNode* minNode(BSTNode* node);
    void inorderHelper(BSTNode* node);
    BSTNode* searchHelper(BSTNode* node, int rollNo);
public:
    BST();
    void insert(Student s);
    void remove(int rollNo);
    Student* search(int rollNo);
    void inorder();
};

#endif