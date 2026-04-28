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
