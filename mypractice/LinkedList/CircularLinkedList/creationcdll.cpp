#include <iostream>
using namespace std;
struct Node{
    int data;
    Node * prev;
    Node * next;
};

//Creation
void creation(Node *&head){
    int n;
    cout<<"Enter the number of nodes you want in the list:";
    cin>>n;
    Node* temp=nullptr;
    for(int i=0;i<n;i++){
    Node *newnode=new Node();
  cout<<"Enter data for node"<<i+1<<":";
  cin>>newnode->data;
  if(head==nullptr){
       head=newnode;
    newnode->prev=head;
    newnode->next=head;
    temp=head;
  }
    
    else{
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=head;
        head->prev=newnode;
        temp=newnode;
    }
    }

}


//Display

void display(Node* head){
    if(head == nullptr){
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "List is: ";

    do {
        cout << temp->data;
        temp = temp->next;
        if(temp != head) cout << "<->"; 
    } while(temp != head);

    cout << endl;
}

//insert at start 
void insertAtBeginning(Node*& head,int value)
{
    Node* newnode = new Node;
    newnode->data = value;

    if(head == nullptr)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    Node* last = head->prev;

    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;
    head->prev = newnode;

    head = newnode;
}


//insertatend

void insertAtEnd(Node*& head,int value)
{
    Node* newnode = new Node;
    newnode->data = value;

    if(head == nullptr)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    Node* last = head->prev;

    last->next = newnode;
    newnode->prev = last;

    newnode->next = head;
    head->prev = newnode;
}
//insertatanypostion
void insertAtPosition(Node*& head, int pos, int value) {
    Node* newnode = new Node();
    newnode->data = value;

    if(head == nullptr) {  
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
        return;
    }

    
    if(pos == 1) {
        Node* last = head->prev;
        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
        head = newnode;
        return;
    }

    
    Node* temp = head;
    int count = 1;
    while(count < pos-1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    Node* last = temp->next;      

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = last;
    last->prev = newnode;

  
    if(temp == head->prev) {
        head->prev = newnode;
    }
}

//delete at start
void deleteAtBeginning(Node*& head)
{
    if(head == nullptr)
    return;

    Node* last = head->prev;
    Node* temp = head;

    head = head->next;

    last->next = head;
    head->prev = last;

    delete temp;
}

//delete at end
void deleteAtEnd(Node*& head)
{
    if(head == nullptr)
    return;

    Node* last = head->prev;
    Node* secondlast = last->prev;

    secondlast->next = head;
    head->prev = secondlast;

    delete last;
}

//delete at any pos
void deleteAtPosition(Node*& head,int pos)
{
    Node* temp = head;

    for(int i=1;i<pos;i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

//update operation
void update(Node* head,int pos,int value)
{
    Node* temp = head;

    for(int i=1;i<pos;i++)
    {
        temp = temp->next;
    }

    temp->data = value;
}
int main() {
    Node* head = nullptr;  
    int choice, value, pos;

    do {
        cout << "\n--- Circular Doubly Linked List Menu ---\n";
        cout << "1. Create List\n";
        cout << "2. Display List\n";
        cout << "3. Insert at Beginning\n";
        cout << "4. Insert at End\n";
        cout << "5. Insert at Position\n";
        cout << "6. Delete at Beginning\n";
        cout << "7. Delete at End\n";
        cout << "8. Delete at Position\n";
        cout << "9. Update Node\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                creation(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 4:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 5:
                cout << "Enter position to insert: ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtPosition(head, pos, value);
                break;
            case 6:
                deleteAtBeginning(head);
                break;
            case 7:
                deleteAtEnd(head);
                break;
            case 8:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteAtPosition(head, pos);
                break;
            case 9:
                cout << "Enter position to update: ";
                cin >> pos;
                cout << "Enter new value: ";
                cin >> value;
                update(head, pos, value);
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 0);

    return 0;
}