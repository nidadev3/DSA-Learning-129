#include<iostream>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
//preorder
void preOrder(Node* root){
   if (root == NULL) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        cout << curr->data << " ";

        if (curr->right)
            st.push(curr->right);

        if (curr->left)
            st.push(curr->left);
    }
}


//inorder
void inOrder(Node* root){
 
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {

        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}


//postorder
void postOrder(Node* root){
 if (root == NULL) return;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left)
            st1.push(curr->left);

        if (curr->right)
            st1.push(curr->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main (){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    //Traversal
    cout<<"PreOrder:";
    preOrder(root);

     cout<<"\nInOrder:";
     inOrder(root);

      cout<<"\nPostOrder:";
     postOrder(root);

     return 0;
}