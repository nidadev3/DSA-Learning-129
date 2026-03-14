#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

void creation(Node* &head) {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of nodes must be at least 1." << endl;
        return;
    }

    Node* temp = nullptr; 

    for (int i = 0; i < n; i++) {
        Node* newnode = new Node();
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> newnode->data;
        newnode->link = nullptr;

        if (head == nullptr) {
            head = newnode; 
            temp = newnode;
        } else {
            temp->link = newnode; 
            temp = newnode;       
        }
    }
}


void printList(Node* head) {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data;
        if (ptr->link != nullptr)
            cout << " -> ";
        ptr = ptr->link;
    }
    cout << " -> NULL" << endl;
}


void deleteHead(Node* &head) {
    if(head == nullptr) {
        cout << "List is empty. Cannot delete head." << endl;
        return;
    }
    Node* temp = head;
    head = head->link;
    delete temp;
    cout << "Head node deleted." << endl;
}


void deleteEnd(Node* &head) {
    if(head == nullptr) {
        cout << "List is empty. Cannot delete end." << endl;
        return;
    }
    if(head->link == nullptr) {
      
        delete head;
        head = nullptr;
        cout << "Last node deleted." << endl;
        return;
    }

    Node* temp = head;
    while(temp->link->link != nullptr) {
        temp = temp->link;
    }
    
    delete temp->link;
    temp->link = nullptr;
    cout << "Last node deleted." << endl;
}


void deleteAtPosition(Node* &head, int pos) {
    if(head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    if(pos <= 0) {
        cout << "Invalid position." << endl;
        return;
    }
    if(pos == 1) {
        deleteHead(head);
        return;
    }

    Node* temp = head;
    for(int i = 1; i < pos-1; i++) {
        if(temp->link == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }
        temp = temp->link;
    }

    Node* nodeToDelete = temp->link;
    if(nodeToDelete == nullptr) {
        cout << "Position out of range." << endl;
        return;
    }

    temp->link = nodeToDelete->link;
    delete nodeToDelete;
    cout << "Node at position " << pos << " deleted." << endl;
}


int main() {
    Node* head = nullptr;

    creation(head);
    printList(head);

   
    deleteHead(head);
    printList(head);

    deleteEnd(head);
    printList(head);

    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    deleteAtPosition(head, pos);
    printList(head);

    return 0;
}