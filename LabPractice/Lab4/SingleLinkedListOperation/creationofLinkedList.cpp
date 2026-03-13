#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if(n <= 0) {
        cout << "Number of nodes must be at least 1." << endl;
        return 0;
    }

    Node* head = nullptr;  
    Node* temp = nullptr;  

    for(int i = 0; i < n; i++) {
        Node* newNode = new Node;   
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> newNode->data;
        newNode->next = nullptr;  
        if(head == nullptr) {
            
            head = newNode;
            temp = newNode;
        } else {
            
            temp->next = newNode;
            temp = newNode; 
        }
    }

    
    Node* ptr = head;
    while(ptr != nullptr) {
        cout << ptr->data;
        if(ptr->next != nullptr)
            cout << " -> ";
        ptr = ptr->next;
    }
    cout << " -> NULL" << endl;

    return 0;
}