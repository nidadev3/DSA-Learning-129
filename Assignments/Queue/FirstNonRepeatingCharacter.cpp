#include <iostream>
using namespace std;
class queue{private:
int *arr;
int capacity;
int size;
int front;
int rear;
public:
queue(int cap){
    capacity=cap;
    arr=new int[capacity];
    size=0;
    front=0;
rear=-1;
}
int getCapacity() {
    return capacity;
}
bool rempty(){
    return size==0;

}
bool rfull(){
    return size==capacity;}
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
}};
void firstNonRepeating(string stream){

}
int main (){
    string stream;
    cout<<"Enter the stream:";
    cin>>;
firstNonRepeating(string stream);
return 0;
}