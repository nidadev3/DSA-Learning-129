#include<iostream>
using namespace std;

class Queue{
private:
    int *arr;
    int capacity;
    int size;
    int front;
    int rear;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is FULL. Cannot enqueue " << val << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = val;

        if (front == -1)
            front = 0;

        size++;

        cout << "Enqueued: " << val << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY." << endl;
            return -1;
        }

        int val = arr[front];

        if (size == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;

        cout << "Dequeued: " << val << endl;
        return val;
    }

   void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue: ";

    int i = front;

    for (int count = 0; count < size; count++) {
        cout << arr[i];

        if (count < size - 1)
            cout << " -> ";     

        i = (i + 1) % capacity;
    }

    cout << endl;
}
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}