#ifndef SINGLYLL_H
#define SINGLYLL_H

#include <string>
using namespace std;

struct SLLNode {
    string courseName;
    SLLNode* next;
    SLLNode(string c) : courseName(c), next(nullptr) {}
};

class SinglyLL {
private:
    SLLNode* head;
    int size;
public:
    SinglyLL();
    ~SinglyLL();
    void insertFront(string course);
    void insertEnd(string course);
    void deleteNode(string course);
    void display();
    int getSize();
};

#endif