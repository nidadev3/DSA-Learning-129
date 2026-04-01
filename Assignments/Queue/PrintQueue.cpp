#include<iostream>
using namespace std;
struct job{
    int id;
    string ownerName;
    string documentName;
};
class queue {
private:
  job *arr;
    int capacity;
    int size;
    int front;
    int rear;

public:
    queue(int cap) {
        capacity = cap;
        arr = new job[capacity];
        size = 0;
        front = 0;
        rear = -1;
    }

    bool rempty() {
        return size == 0;
    }

    bool rfull() {
        return size == capacity;
    }

    void enqueue(job b) {
        if (rfull()) return;
        rear = (rear + 1) % capacity;
        arr[rear] = b;
        size++;
    }

 job dequeue() {
    if(rempty()) return job(); 
    job b = arr[front];        
    front = (front+1) % capacity;
    size--;
    return b;                   
}
}