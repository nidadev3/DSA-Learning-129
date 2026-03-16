#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

// Method 1: delete from head
void deletefromhead(Node* &head)
{
    if(head == nullptr)
        return;

    Node* temp = head;
    head = head->next;

    if(head != nullptr)
        head->prev = nullptr;

    delete temp;
}

// Method 2: delete from head
void deleteFromHead(Node* &head)
{
    if(head == nullptr)
        return;

    head = head->next;

    if(head != nullptr)
    {
        delete head->prev;
        head->prev = nullptr;
    }
}

// Delete from end
void deletefromend(Node *&head)
{
    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;

    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    if(temp->prev != nullptr)
        temp->prev->next = nullptr;
    else
        head = nullptr;

    delete temp;
}

//Delete form any positon 
void deleteanypos(Node* &head,int pos){
    
}

// Display list
void display(Node* head)
{
    Node* temp = head;

    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    // Creating nodes
    Node* head = new Node{10,nullptr,nullptr};
    Node* second = new Node{20,nullptr,nullptr};
    Node* third = new Node{30,nullptr,nullptr};
    Node* fourth = new Node{40,nullptr,nullptr};
    Node* fifth = new Node{50,nullptr,nullptr};

    // Linking nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    cout<<"Original List: ";
    display(head);

    cout<<"After deletefromhead(): ";
    deletefromhead(head);
    display(head);

    cout<<"After deleteFromHead(): ";
    deleteFromHead(head);
    display(head);

    cout<<"After deletefromend(): ";
    deletefromend(head);
    display(head);

   
    return 0;
}