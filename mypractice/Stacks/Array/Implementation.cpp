#include<iostream>
using namespace std;
class stack{
    private: 
    int arr[100];
    int top;
    int capacity;

    public:
    stack(int capacity)
    {
        this.capacity=capacity;
        top=-1;
    }
   void push( int x){
        if(top==capacity-1){
            cout<<"The stack is overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
        cout<<x<<"pushed to stack"<<endl;

    }
    int pop(){
        if(top==-1){
             {
            cout << "Underflow! Stack is empty.\n";
            return -1;
        }
        return arr[top--]
        }

    }
     int peek() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

}