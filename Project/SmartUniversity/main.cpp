#include <iostream>
#include "modules/StudentManager.h"
#include "modules/CourseManager.h"
#include "modules/LibraryManager.h"
#include "modules/ComplaintManager.h"
#include "modules/CampusGraph.h"
#include "modules/UndoRedoManager.h"
#include "modules/HistoryManager.h"
using namespace std;

int main() {
    StudentManager studentManager;
    CourseManager courseManager;
    LibraryManager libraryManager;
    ComplaintManager complaintManager;
    CampusGraph campusGraph;
    UndoRedoManager undoRedoManager;
    HistoryManager historyManager;

    campusGraph.setupCampus();

    int choice;
    do {
        cout << "\n===== Smart University System =====" << endl;
        cout << "1. Student Management" << endl;
        cout << "2. Course Registration" << endl;
        cout << "3. Library Management" << endl;
        cout << "4. Complaint Management" << endl;
        cout << "5. Campus Navigation" << endl;
        cout << "6. Undo / Redo" << endl;
        cout << "7. View History" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int sub;
            cout << "\n1. Add Student  2. Search  3. Delete  4. Display All  5. Display Sorted by CGPA" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub == 1) {
                Student s;
                cout << "Roll No: ";
                cin >> s.rollNo;
                cin.ignore();
                cout << "Name: ";
                getline(cin, s.name);
                cout << "Department: ";
                getline(cin, s.department);
                cout << "CGPA: ";
                cin >> s.cgpa;
                cin.ignore();
                studentManager.addStudent(s);
                undoRedoManager.doAction(s);
                historyManager.viewRecord(s);
                cout << "Student added: " << s.name << endl;
            } else if (sub == 2) {
                int roll;
                cout << "Enter Roll No: ";
                cin >> roll;
                cin.ignore();
                studentManager.searchByRollNo(roll);
            } else if (sub == 3) {
                int roll;
                cout << "Enter Roll No: ";
                cin >> roll;
                cin.ignore();
                studentManager.deleteStudent(roll);
            } else if (sub == 4) {
                studentManager.displayAll();
            } else if (sub == 5) {
                studentManager.displaySortedByCGPA();
            }

        } else if (choice == 2) {
            int sub;
            cout << "\n1. Register Course  2. Drop Course  3. Display Courses" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub == 1) {
                string course;
                cout << "Course name: ";
                getline(cin, course);
                courseManager.registerCourse(course);
            } else if (sub == 2) {
                string course;
                cout << "Course name: ";
                getline(cin, course);
                courseManager.dropCourse(course);
            } else if (sub == 3) {
                courseManager.displayCourses();
            }

        } else if (choice == 3) {
            int sub;
            cout << "\n1. Add Book  2. Search Book  3. Reserve Book  4. Process Reservation  5. Display Books" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub == 1) {
                Book b;
                cout << "Book ID: ";
                cin >> b.bookId;
                cin.ignore();
                cout << "Title: ";
                getline(cin, b.title);
                cout << "Author: ";
                getline(cin, b.author);
                b.isAvailable = true;
                libraryManager.addBook(b);
                cout << "Book added!" << endl;
            } else if (sub == 2) {
                int id;
                cout << "Book ID: ";
                cin >> id;
                cin.ignore();
                libraryManager.searchBook(id);
            } else if (sub == 3) {
                Student s;
                cout << "Roll No: ";
                cin >> s.rollNo;
                cin.ignore();
                cout << "Name: ";
                getline(cin, s.name);
                s.department = "";
                s.cgpa = 0;
                libraryManager.reserveBook(s);
            } else if (sub == 4) {
                libraryManager.processReservation();
            } else if (sub == 5) {
                libraryManager.displayBooks();
            }

        } else if (choice == 4) {
            int sub;
            cout << "\n1. Add Complaint  2. Process Complaint  3. Add Token  4. Process Token  5. Add Emergency  6. Process Emergency  7. Undo" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            Student s;
            if (sub == 1 || sub == 3 || sub == 5) {
                cout << "Roll No: ";
                cin >> s.rollNo;
                cin.ignore();
                cout << "Name: ";
                getline(cin, s.name);
                s.department = "";
                s.cgpa = 0;
            }
            if (sub == 1) complaintManager.addNormalComplaint(s);
            else if (sub == 2) complaintManager.processNormalComplaint();
            else if (sub == 3) complaintManager.addToken(s);
            else if (sub == 4) complaintManager.processToken();
            else if (sub == 5) complaintManager.addEmergency(s);
            else if (sub == 6) complaintManager.processEmergency();
            else if (sub == 7) complaintManager.undoLast();

        } else if (choice == 5) {
            int sub;
            cout << "\n1. Display Map  2. BFS + DFS  3. Shortest Path (Dijkstra)" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();
            if (sub == 1) campusGraph.displayMap();
            else if (sub == 2) campusGraph.exploreAll(0);
            else if (sub == 3) campusGraph.findShortestPath(0);

        } else if (choice == 6) {
            int sub;
            cout << "\n1. Undo  2. Redo  3. Display" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();
            if (sub == 1) undoRedoManager.undo();
            else if (sub == 2) undoRedoManager.redo();
            else if (sub == 3) undoRedoManager.displayStacks();

        } else if (choice == 7) {
            int sub;
            cout << "\n1. Go Back  2. Go Forward  3. Display History" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();
            if (sub == 1) historyManager.goBack();
            else if (sub == 2) historyManager.goForward();
            else if (sub == 3) historyManager.displayHistory();
        }

    } while (choice != 0);

    cout << "Goodbye!" << endl;
    return 0;
}