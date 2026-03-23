#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
    Node(int data){
        this.data=data;
        link=nullptr
    }
};
class stack{
    private:
    Node* top;
    public:
    stack(){
        top=nullptr;
    }
    bool isEmpty(){
        retun top=nullptr;
    }
    void push(int x){
        Node* newnode=new Node(x);
        newnode->next=top;
        top=newnode;
        cout<<x<<"pushed in to the stack";
    }
    void pop (){
        if(isEmpty){
            cout<<"Stack is overflow";
            return -1;
        }
        Node* temp=top;
        cout<<top->data<<"is popped";
        top=top->next;
        delete temp;


    }
    void peak(){
          if(isEmpty){
            cout<<"Stack is overflow";
            return -1;
        }
      return  cout<<Top->data<<"is the top value";
    }
}