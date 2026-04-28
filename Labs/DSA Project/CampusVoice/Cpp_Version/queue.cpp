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

