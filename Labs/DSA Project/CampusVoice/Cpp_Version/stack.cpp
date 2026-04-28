#include <iostream>
#include "Stack.h"

using namespace std;

// Constructor
Stack::Stack() {
    top = -1;
}
//if Empty 
bool Stack::isEmpty() {
    return top == -1;
}

//push
void Stack::push(Complaint c) {
    if (top >= 99) {
        cout << "Stack Overflow!" << endl;
        return;
    }

    arr[++top] = c;
    cout << "Complaint marked as resolved!" << endl;
}

//pop
Complaint Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        Complaint empty = {-1, "", "", "", false, "empty"};
        return empty;
    }

    return arr[top--];
}

//Display 
void Stack::display() {
    if (isEmpty()) {
        cout << "No resolved complaints!" << endl;
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << "ID: " << arr[i].id << endl;
        cout << "Name: " << arr[i].studentName << endl;
        cout << "Category: " << arr[i].category << endl;
        cout << "Urgent: " << (arr[i].isUrgent ? "Yes" : "No") << endl;
        cout << "Status: " << arr[i].status << endl;
        cout << "-------------------" << endl;
    }
}