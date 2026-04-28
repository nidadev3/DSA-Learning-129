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

//main
int main(){

int choice;

do {
    cout << "\n===== CampusVoice System =====\n";
    cout << "1. Submit Complaint\n";
    cout << "2. Process Next Complaint\n";
    cout << "3. View Pending Complaints\n";
    cout << "4. View Resolved Complaints\n";
    cout << "5. View All Complaints\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;}


    //1-Submit complaint
     if (choice == 1) {

            Complaint c;

            c.id = nextID++;

            cout << "Enter Student Name: ";
            cin >> c.studentName;

            cout << "Enter Description: ";
            cin >> c.description;

            cout << "Enter Category (lab/hostel/cafe): ";
            cin >> c.category;

            cout << "Is Urgent? (1 = Yes, 0 = No): ";
            cin >> c.isUrgent;

            c.status = "pending";
            //in array
           allComplaints[totalComplaints++] = c;
           //to queue
           if (c.isUrgent)
                urgentQueue.enqueue(c);
            else
                normalQueue.enqueue(c);

            cout << "Complaint submitted successfully!\n";
        }

        
    while(choice !=6);
    return 0;}