#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include "../include/DoublyLL.h"

class HistoryManager {
private:
    DoublyLL history;
public:
    void viewRecord(Student s);
    void goBack();
    void goForward();
    void displayHistory();
};

#endif