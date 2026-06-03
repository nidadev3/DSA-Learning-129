#include <iostream>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Sorting.h"
#include "BST.h"
#include "AVLTree.h"
#include "Graph.h"
 
using namespace std;
 
// Objects
Queue    normalQueue;
PriorityQueue urgentQueue;
Stack    resolvedStack;
LinkedList historyList;
Sorting  sorter;
BST      bst;
AVLTree  avl;
Graph    graph;
 
// Array for all complaints
Complaint allComplaints[100];
int totalComplaints = 0;
int nextID = 1;
 
int main() {
 
    int choice;
 
    do {
        cout << "\n===== CampusVoice System =====\n";
        cout << "1.  Submit Complaint\n";
        cout << "2.  Process Next Complaint\n";
        cout << "3.  View Pending Complaints\n";
        cout << "4.  View Resolved Complaints\n";
        cout << "5.  View All Complaints\n";
        cout << "--- SORTING ---\n";
        cout << "6.  Sort Complaints\n";
        cout << "--- BST ---\n";
        cout << "7.  Search Complaint (BST)\n";
        cout << "8.  Delete from BST\n";
        cout << "9.  BST Traversals\n";
        cout << "--- AVL TREE ---\n";
        cout << "10. Search Complaint (AVL)\n";
        cout << "11. AVL Inorder Display\n";
        cout << "--- GRAPH ---\n";
        cout << "12. Graph Operations (BFS/DFS/Dijkstra/Kruskal)\n";
        cout << "--- SYSTEM ---\n";
        cout << "0.  Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
 
        // 1 - Submit Complaint
        if (choice == 1) {
 
            Complaint c;
            c.id = nextID++;
 
            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, c.studentName);
 
            cout << "Enter Description: ";
            getline(cin, c.description);
 
            cout << "Enter Category (Lab/Hostel/Cafe/Other): ";
            cin >> c.category;
 
            cout << "Is Urgent? (1 = Yes, 0 = No): ";
            cin >> c.isUrgent;
 
            c.status = "pending";
 
            // Store in array
            allComplaints[totalComplaints++] = c;
 
            // Queue logic
            if (c.isUrgent)
                urgentQueue.enqueue(c);
            else
                normalQueue.enqueue(c);
 
            // Insert into BST and AVL for fast search
            bst.insert(c);
            avl.insert(c);
 
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
 
                    for (int i = 0; i < totalComplaints; i++)
                        if (allComplaints[i].id == c.id) {
                            allComplaints[i].status = "resolved";
                            break;
                        }
 
                    cout << "Complaint RESOLVED!\n";
                }
                else {
                    c.status = "in progress";
                    normalQueue.enqueue(c);
 
                    for (int i = 0; i < totalComplaints; i++)
                        if (allComplaints[i].id == c.id) {
                            allComplaints[i].status = "in progress";
                            break;
                        }
 
                    cout << "Complaint is IN PROGRESS.\n";
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
                cout << "ID: "       << allComplaints[i].id          << endl;
                cout << "Name: "     << allComplaints[i].studentName  << endl;
                cout << "Category: " << allComplaints[i].category     << endl;
                cout << "Status: "   << allComplaints[i].status       << endl;
                cout << "----------------------\n";
            }
        }
 
        // 6 - Sort
        else if (choice == 6) {
            sorter.sortMenu(allComplaints, totalComplaints);
        }
 
        // 7 - BST Search
        else if (choice == 7) {
            int id;
            cout << "Enter Complaint ID to search: ";
            cin >> id;
            bst.search(id);
        }
 
        // 8 - BST Delete
        else if (choice == 8) {
            int id;
            cout << "Enter Complaint ID to delete from BST: ";
            cin >> id;
            bst.deleteNode(id);
        }
 
        // 9 - BST Traversals
        else if (choice == 9) {
            bst.traversalMenu();
        }
        else if (choice == 12) {
            graph.graphMenu();
        }
 
        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }
 
    } while (choice != 0);
 
    cout << "Exiting CampusVoice...\n";
    return 0;
}