#include "ComplaintManager.h"
#include <iostream>
using namespace std;

void ComplaintManager::addNormalComplaint(Student s) {
    normalComplaints.enqueue(s);
    undoStack.push(s);
    cout << "Complaint added: " << s.name << endl;
}

void ComplaintManager::processNormalComplaint() {
    if (!normalComplaints.isEmpty()) {
        Student s = normalComplaints.dequeue();
        cout << "Processing complaint: " << s.name << endl;
    } else {
        cout << "No complaints" << endl;
    }
}

void ComplaintManager::addToken(Student s) {
    tokenQueue.enqueue(s);
    cout << "Token issued to: " << s.name << endl;
}

void ComplaintManager::processToken() {
    if (!tokenQueue.isEmpty()) {
        Student s = tokenQueue.dequeue();
        cout << "Token processed: " << s.name << endl;
    } else {
        cout << "No tokens" << endl;
    }
}

void ComplaintManager::addEmergency(Student s) {
    emergencyHeap.insert(s);
    cout << "Emergency added: " << s.name << endl;
}

void ComplaintManager::processEmergency() {
    if (!emergencyHeap.isEmpty()) {
        Student s = emergencyHeap.extractMin();
        cout << "Emergency processed: " << s.name << endl;
    } else {
        cout << "No emergencies" << endl;
    }
}

void ComplaintManager::undoLast() {
    if (!undoStack.isEmpty()) {
        Student s = undoStack.pop();
        cout << "Undo: removed complaint of " << s.name << endl;
    } else {
        cout << "Nothing to undo" << endl;
    }
}