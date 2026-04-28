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

//RemoveComplaint
Complaint Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        Complaint empty;
        return empty;
    }

    return arr[front++];
}

//DisplayComplaints
void Queue::display() {
    if (isEmpty()) {
        cout << "No pending complaints!" << endl;
        return;
    }

    for (int i = front; i <= rear; i++) {
       cout << "ID: " << arr[i].id << endl;
cout << "Name: " << arr[i].studentName << endl;
cout << "Category: " << arr[i].category << endl;
cout << "Urgent: " << (arr[i].isUrgent ? "Yes" : "No") << endl;
cout << "Status: " << arr[i].status << endl;
cout << "------------------------" << endl;
    }}