#include "HistoryManager.h"
#include <iostream>
using namespace std;

void HistoryManager::viewRecord(Student s) {
    history.insertFront(s);
    cout << "Viewing: " << s.name << endl;
}

void HistoryManager::goBack() {
    history.goBack();
}

void HistoryManager::goForward() {
    history.goForward();
}

void HistoryManager::displayHistory() {
    cout << "--- View History ---" << endl;
    history.display();
}