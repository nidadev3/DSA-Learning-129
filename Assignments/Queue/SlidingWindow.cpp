#include<iostream>
using namespace std;
class queue{
    private:
    int* arr;
    int size;
    int front;
    int rear;
    public:
    queue(int n){
  arr=new arr[n];
  size=n;
  front=0;
  rear=-1;
}
bool isfull(){
    return rear=size-1;
}
bool isempty(){
    return front>rear;
}
void equeue(int value){
    if(isfull()){
        cout<<"Queue is overflow.";
    }
    rear++;
    arr[rear]=x;
}
void dequeue(){
    if(isempty()){
        cout<<"Queue is underflow.";
    }
front++;
}
int getfront(){
    return front;
}
}