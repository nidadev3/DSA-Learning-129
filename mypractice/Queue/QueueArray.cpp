#include<iostream>
using namespace std;

class Queue{
private:
    int arr[5];
    int front;
    int end;
public:
    Queue(){
        front=0;
        end=-1;
    }

    bool empty(){
        return (front > end);
    }

    bool full(){
        return (end == 4);
    }

    void push(int value){
        if(full()){
            cout<<"Queue is Full\n";
            return;
        }
        arr[++end] = value;
    }

    int pop(){
        if(empty()){
            cout<<"Queue is Empty\n";
            return -1;
        }
        return arr[front++];
    }

    void display(){
        if(empty()){
            cout<<"Queue is Empty\n";
            return;
        }
        for(int i = front; i <= end; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    q.display();

    cout << q.pop() << endl;

    q.display();

    return 0;
}