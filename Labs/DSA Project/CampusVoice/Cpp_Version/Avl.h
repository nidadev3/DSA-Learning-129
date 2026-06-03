#ifndef AVLTREE_H
#define AVLTREE_H
 
#include "Complaint.h"
 
struct AVLNode {
    Complaint data;
    AVLNode* left;
    AVLNode* right;
    int height;
};
 
class AVLTree {
private:
    AVLNode* root;
 
    int height(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insertHelper(AVLNode* node, Complaint c);
    AVLNode* findMin(AVLNode* node);
    AVLNode* deleteHelper(AVLNode* node, int id);
    void inorderHelper(AVLNode* node);
 
public:
    AVLTree();
    void insert(Complaint c);
    void deleteNode(int id);
    Complaint search(int id);
    void inorder();
};
 
#endif