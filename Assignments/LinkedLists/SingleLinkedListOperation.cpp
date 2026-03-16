#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *link;
};

// Creation of Linked List
void creation(Node *&head)
{
    int n;
    cout<<"Enter the number of nodes in the linked list: ";
    cin>>n;

    Node* temp = nullptr;

    for(int i=0;i<n;i++)
    {
        Node* newnode = new Node();
        cout<<"Enter value of node "<<i+1<<": ";
        cin>>newnode->data;
        newnode->link = nullptr;

        if(head == nullptr)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->link = newnode;
            temp = newnode;
        }
    }
}

// Insert at head
void insertAtHead(Node* &head, int value)
{
    Node* newnode = new Node();
    newnode->data = value;
    newnode->link = head;
    head = newnode;

    cout<<"Node inserted at head."<<endl;
}

// Insert at end
void insertAtEnd(Node* &head, int value)
{
    Node* newnode = new Node();
    newnode->data = value;
    newnode->link = nullptr;

    if(head == nullptr)
    {
        head = newnode;
        cout<<"Node inserted at end."<<endl;
        return;
    }

    Node* temp = head;

    while(temp->link != nullptr)
        temp = temp->link;

    temp->link = newnode;

    cout<<"Node inserted at end."<<endl;
}

// Insert at position
void insertAtPosition(Node* &head, int value, int pos)
{
    if(pos == 1)
    {
        insertAtHead(head,value);
        return;
    }

    Node* newnode = new Node();
    newnode->data = value;

    Node* temp = head;

    for(int i=1;i<pos-1;i++)
    {
        if(temp == nullptr)
        {
            cout<<"Position out of range"<<endl;
            return;
        }
        temp = temp->link;
    }

    newnode->link = temp->link;
    temp->link = newnode;

    cout<<"Node inserted at position "<<pos<<endl;
}

// Update first node
void updateFirstNode(Node* head,int value)
{
    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    head->data = value;

    cout<<"First node updated"<<endl;
}

// Update last node
void updateLastNode(Node* head,int value)
{
    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;

    while(temp->link != nullptr)
        temp = temp->link;

    temp->data = value;

    cout<<"Last node updated"<<endl;
}

// Update at position
void updateAtPosition(Node* head,int pos,int value)
{
    Node* temp = head;

    for(int i=1;i<pos;i++)
    {
        if(temp == nullptr)
        {
            cout<<"Position out of range"<<endl;
            return;
        }

        temp = temp->link;
    }

    temp->data = value;

    cout<<"Node updated at position "<<pos<<endl;
}

// Delete head
void deleteHead(Node* &head)
{
    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;
    head = head->link;
    delete temp;

    cout<<"Head node deleted"<<endl;
}

// Delete end
void deleteEnd(Node* &head)
{
    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    if(head->link == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while(temp->link->link != nullptr)
        temp = temp->link;

    delete temp->link;
    temp->link = nullptr;

    cout<<"Last node deleted"<<endl;
}

// Delete at position
void deleteAtPosition(Node* &head,int pos)
{
    if(pos == 1)
    {
        deleteHead(head);
        return;
    }

    Node* temp = head;

    for(int i=1;i<pos-1;i++)
    {
        if(temp->link == nullptr)
        {
            cout<<"Position out of range"<<endl;
            return;
        }

        temp = temp->link;
    }

    Node* nodeToDelete = temp->link;

    if(nodeToDelete == nullptr)
    {
        cout<<"Position out of range"<<endl;
        return;
    }

    temp->link = nodeToDelete->link;

    delete nodeToDelete;

    cout<<"Node deleted at position "<<pos<<endl;
}

// Display
void display(Node* head)
{
    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;

    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }

    cout<<endl;
}

// Main
int main()
{
    Node* head = nullptr;
    int value,pos;

    creation(head);

    cout<<"Linked List: ";
    display(head);

    cout<<"Enter value to insert at head: ";
    cin>>value;
    insertAtHead(head,value);
    display(head);

    cout<<"Enter value to insert at end: ";
    cin>>value;
    insertAtEnd(head,value);
    display(head);

    cout<<"Enter value and position to insert: ";
    cin>>value>>pos;
    insertAtPosition(head,value,pos);
    display(head);

    cout<<"Enter value to update first node: ";
    cin>>value;
    updateFirstNode(head,value);
    display(head);

    cout<<"Enter value to update last node: ";
    cin>>value;
    updateLastNode(head,value);
    display(head);

    cout<<"Enter position and value to update: ";
    cin>>pos>>value;
    updateAtPosition(head,pos,value);
    display(head);

    cout<<"Deleting first node..."<<endl;
    deleteHead(head);
    display(head);

    cout<<"Deleting last node..."<<endl;
    deleteEnd(head);
    display(head);

    cout<<"Enter position to delete: ";
    cin>>pos;
    deleteAtPosition(head,pos);
    display(head);

    return 0;
}