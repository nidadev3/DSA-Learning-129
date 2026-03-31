#include <iostream>
using namespace std;

class queue {
private:
    char *arr;
    int capacity;
    int size;
    int front;
    int rear;

public:
    queue(int cap) {
        capacity = cap;
        arr = new char[capacity];
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

    void enqueue(char value) {
        if (rfull()) return;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (rempty()) return;
        front = (front + 1) % capacity;
        size--;
    }

    char getFront() {
        if (rempty()) return '#';
        return arr[front];
    }
};

void firstNonRepeating(string stream) {
    int freq[26] = {0};
    queue q(100);

    for (int i = 0; i < stream.length(); i++) {
        char ch = stream[i];

        freq[ch - 'a']++;
        q.enqueue(ch);

        while (!q.rempty() && freq[q.getFront() - 'a'] > 1) {
            q.dequeue();
        }

        if (q.rempty()) {
            cout << "Queue is empty";
        } else {
            cout << q.getFront() << " ";
        }
    }
}

int main() {
    string stream;
    cout << "Enter the stream: ";
    cin >> stream;

    firstNonRepeating(stream);
    return 0;
}