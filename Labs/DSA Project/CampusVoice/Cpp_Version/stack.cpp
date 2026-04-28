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