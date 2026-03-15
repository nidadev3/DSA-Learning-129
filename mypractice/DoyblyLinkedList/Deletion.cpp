#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
//methodno1 for delteting head node
void deletefromhead(Node* &head)
{
    if(head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}