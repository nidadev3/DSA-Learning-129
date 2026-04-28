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