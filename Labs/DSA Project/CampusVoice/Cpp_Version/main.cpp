#include <iostream>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

// objects
Queue normalQueue;
PriorityQueue urgentQueue;
Stack resolvedStack;
LinkedList historyList;

// Array for all complaints
Complaint allComplaints[100];
int totalComplaints = 0;
int nextID = 1;

int main() {

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
        cin >> choice;

        // 1 - Submit Complaint
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

            // store in array
            allComplaints[totalComplaints++] = c;

            // send to queue
            if (c.isUrgent)
                urgentQueue.enqueue(c);
            else
                normalQueue.enqueue(c);

            cout << "Complaint submitted successfully!\n";
        }

        // 2 - Process Complaint
        else if (choice == 2) {

            Complaint c;

            if (!urgentQueue.isEmpty())
                c = urgentQueue.dequeue();
            else
                c = normalQueue.dequeue();

            if (c.id != -1) {

                cout << "\nProcessing Complaint ID: " << c.id << endl;

                int adminChoice;
                cout << "1. Mark as Resolved\n";
                cout << "2. Mark as In Progress\n";
                cout << "Enter choice: ";
                cin >> adminChoice;

                if (adminChoice == 1) {

                    c.status = "resolved";

                    resolvedStack.push(c);
                    historyList.insert(c);

                    cout << "Complaint VERIFIED and RESOLVED!\n";
                }
                else {

                    c.status = "in progress";

                    normalQueue.enqueue(c);

                    cout << "Complaint is IN PROGRESS. Please wait...\n";
                }
            }
        }

        // 3 - Pending
        else if (choice == 3) {

            cout << "\n--- URGENT COMPLAINTS ---\n";
            urgentQueue.display();

            cout << "\n--- NORMAL COMPLAINTS ---\n";
            normalQueue.display();
        }

        // 4 - Resolved
        else if (choice == 4) {

            cout << "\n--- RESOLVED COMPLAINTS ---\n";
            resolvedStack.display();
        }

        // 5 - All
        else if (choice == 5) {

            cout << "\n--- ALL COMPLAINTS ---\n";

            for (int i = 0; i < totalComplaints; i++) {

                cout << "ID: " << allComplaints[i].id << endl;
                cout << "Name: " << allComplaints[i].studentName << endl;
                cout << "Category: " << allComplaints[i].category << endl;
                cout << "Status: " << allComplaints[i].status << endl;
                cout << "----------------------\n";
            }
        }

    } while (choice != 6);

    cout << "Exiting system...\n";

    return 0;
}