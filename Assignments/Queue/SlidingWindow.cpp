#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int size;
    int front;
    int rear;

public:
    Queue(int n) {
        arr = new int[n];
        size = n;
        front = 0;
        rear = -1;
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(int value) {
        if(isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear++;
        arr[rear] = value;
    }

    void dequeue() {
        if(isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    int findMax() {
        int maxVal = arr[front];
        for(int i = front; i <= rear; i++) {
            if(arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }
};

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    int k;
    cout << "Enter window size: ";
    cin >> k;

    Queue q(k);

    for(int i = 0; i < k; i++) {
        q.enqueue(arr[i]);
    }

    cout << q.findMax() << " ";

    for(int i = k; i < n; i++) {
        q.dequeue();
        q.enqueue(arr[i]);
        cout << q.findMax() << " ";
    }

    return 0;
}