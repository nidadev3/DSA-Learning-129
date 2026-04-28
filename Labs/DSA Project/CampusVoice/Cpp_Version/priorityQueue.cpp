#include <iostream>
#include "PriorityQueue.h"

using namespace std;

// Constructor
PriorityQueue::PriorityQueue() {
    size = 0;
}

//if Empty
bool PriorityQueue::isEmpty() {
    return size == 0;
}

//Adding important Complaintz
void PriorityQueue::enqueue(Complaint c) {
    if (size >= 100) {
        cout << "Priority Queue Full!" << endl;
        return;
    }

    int i;
    for (i = size - 1; i >= 0; i--) {
        if (arr[i].isUrgent == false && c.isUrgent == true) {
            arr[i + 1] = arr[i];
        } else {
            break;
        }
    }

    arr[i + 1] = c;
    size++;

    cout << "Complaint added to Priority Queue!" << endl;
}

//Remove
Complaint PriorityQueue::dequeue() {
    if (isEmpty()) {
        cout << "Priority Queue Empty!" << endl;
        Complaint empty;
        return empty;
    }

    Complaint c = arr[0];

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    return c;
}

//Display
void PriorityQueue::display() {
    if (isEmpty()) {
        cout << "No urgent complaints!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "ID: " << arr[i].id << endl;
        cout << "Name: " << arr[i].studentName << endl;
        cout << "Urgent: " << (arr[i].isUrgent ? "Yes" : "No") << endl;
        cout << "-------------------" << endl;
    }
}