#include <iostream>
#include "Queue.h"

using namespace std;
//constructor
Queue::Queue() {
    front = 0;
    rear = -1;
}

//ifEmpty
bool Queue::isEmpty() {
    return (front > rear);
}

//AddComplaint
void Queue::enqueue(Complaint c) {
    if (rear >= 99) {
        cout << "Queue is full!" << endl;
        return;
    }

    arr[++rear] = c;
    cout << "Complaint added to queue successfully!" << endl;
}
