#ifndef BST_H
#define BST_H
 
#include "Complaint.h"
 
struct BSTNode {
    Complaint data;
    BSTNode* left;
    BSTNode* right;
};
 
class BST {
private:
    BSTNode* root;
 
    BSTNode* insertHelper(BSTNode* node, Complaint c);
    BSTNode* deleteHelper(BSTNode* node, int id);
    BSTNode* findMin(BSTNode* node);
    void inorderHelper(BSTNode* node);
    void preorderHelper(BSTNode* node);
    void postorderHelper(BSTNode* node);
 
public:
    BST();
    void insert(Complaint c);
    void deleteNode(int id);
    Complaint search(int id);
    void inorder();
    void preorder();
    void postorder();
    void traversalMenu();
};
 
#endif