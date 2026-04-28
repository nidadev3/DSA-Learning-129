#include <iostream>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Stack.h"
#include "LinkedList.h"

using namespace std;
//objects
Queue normalQueue;
PriorityQueue urgentQueue;
Stack resolvedStack;
LinkedList historyList;
//Array for all complaints
Complaint allComplaints[100];
int totalComplaints = 0;
int nextID = 1;