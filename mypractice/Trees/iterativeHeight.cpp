#include <iostream>
#include <queue>
using namespace std;

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

int height(Node* root) {
    if (root == NULL)
        return -1;

    queue<Node*> q;
    q.push(root);

    int h = 0;

    while (!q.empty()) {

        int size = q.size(); 

        while (size--) {
            Node* curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        h++; 
    }

    return h;
}


Node* createTree() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(2);
    root->left->right = new Node(7);

    return root;
}

int main() {
    Node* root = createTree();

    cout << "Height of tree: " << height(root) << endl;

    return 0;
}