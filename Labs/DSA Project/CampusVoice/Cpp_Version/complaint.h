#ifndef COMPLAINT_H
#define COMPLAINT_H
#include <string>
using namespace std;
struct Complaint{
    int id;
    string studentName;
    string description;
    string category; //lab,hostel,cafe
    bool isUrgent;
    string status;   //pending or resolved
};

#endif
