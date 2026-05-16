#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
};
Node* createNode(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}
