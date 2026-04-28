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