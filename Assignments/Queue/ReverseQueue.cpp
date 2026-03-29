#include<iostream>
using namespace std;
class Queue{
    private:
        int * arr;
        int capacity;
        int front;
        int rear;
        int size;
    public:
        Queue(int cap){
            capacity=cap;
            arr=new int[capacity];
            front=0;
            rear=-1;
            size=0;

        }
        int getCapacity() {
    return capacity;
}
        bool rempty(){
            return size==0;
        }
        bool rfull(){
            return size==capacity;
        }
        void enqueue(int value){
            if(rfull()){
                cout<<"Queue is full\n";
                return;

            }
            rear=(rear+1)%capacity;
            arr[rear]=value;    
            size++;

        }
        int dequeue(){
            if(rempty()){
                cout<<"Queue is empty\n";
                return -1;
            }
            int value=arr[front];
            front=(front+1)%capacity;
            size--;
            return value;
        }
        void display(){
            if(rempty()){
                cout<<"Queue is empty\n";
                return;
            }
            for(int i=0;i<size;i++){
                cout<<arr[(front+i)%capacity]<<" ";
            }
            cout<<endl;
        }

};

class stack{
    private:
        int * arr;
        int capacity;
        int top;
    public:
        stack(int cap){
            capacity=cap;
            arr=new int[capacity];
            top=-1;

        }
        bool sempty(){
            return top==-1;
        }
        bool sfull(){
            return top==capacity-1;
        }
        void push(int value){
            if(sfull()){
                cout<<"Stack is full\n";
                return;

            }
            else{
            arr[++top]=value;    
            }

        }
        int pop(){
            if(sempty()){
                cout<<"Stack is empty\n";
                return -1;
            }
            return arr[top--];
            
        }

};
void reverseQueue(Queue &q){
  stack s(q.getCapacity());
    while(!q.rempty()){
        s.push(q.dequeue());
    }
    while(!s.sempty()){
        q.enqueue(s.pop());
    }
}
int main(){
    cout<<"Enter the capacity of the queue: ";
    int cap;
    cin>>cap;
    Queue q(cap);
    
    cout<<"Enter the elements:\n";
    for(int i=0;i<cap;i++){
        int value;
        cin>>value;
        q.enqueue(value);
    }
    cout<<"Original Queue: ";
    q.display();
    reverseQueue(q);
    cout<<"Reversed Queue: ";
    q.display();
    return 0;
}