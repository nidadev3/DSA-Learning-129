#ifndef COMPLAINTMANAGER_H
#define COMPLAINTMANAGER_H

#include "../include/Queue.h"
#include "../include/CircularQueue.h"
#include "../include/MinHeap.h"
#include "../include/Stack.h"

class ComplaintManager {
private:
    Queue normalComplaints;
    CircularQueue tokenQueue;
    MinHeap emergencyHeap;
    Stack undoStack;
public:
    void addNormalComplaint(Student s);
    void processNormalComplaint();
    void addToken(Student s);
    void processToken();
    void addEmergency(Student s);
    void processEmergency();
    void undoLast();
};

#endif