#include <iostream>
#include "modules/StudentManager.h"
#include "modules/CourseManager.h"
#include "modules/LibraryManager.h"
#include "modules/ComplaintManager.h"
#include "modules/CampusGraph.h"
#include "modules/UndoRedoManager.h"
#include "modules/HistoryManager.h"
#include "include/SearchAlgorithms.h"
#include "include/SortingAlgorithms.h"
using namespace std;

int main() {
    StudentManager studentManager;
    CourseManager courseManager;
    LibraryManager libraryManager;
    ComplaintManager complaintManager;
    CampusGraph campusGraph;
    UndoRedoManager undoRedoManager;
    HistoryManager historyManager;
    SearchAlgorithms searcher;
    SortingAlgorithms sorter;

    campusGraph.setupCampus();

    int choice;
    do {
        cout << "\n===== Smart University System =====" << endl;
        cout << "1.  Student Management" << endl;
        cout << "2.  Course Registration" << endl;
        cout << "3.  Library Management" << endl;
        cout << "4.  Complaint Management" << endl;
        cout << "5.  Campus Navigation" << endl;
        cout << "6.  Undo / Redo" << endl;
        cout << "7.  View History" << endl;
        cout << "8.  Search & Sort Engine" << endl;
        cout << "0.  Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        // =====================
        // MODULE 1 — STUDENT
        // =====================
        if (choice == 1) {
            int sub;
            cout << "\n--- Student Management ---" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. Search by Roll No" << endl;
            cout << "3. Delete Student" << endl;
            cout << "4. Display All" << endl;
            cout << "5. Display Sorted by CGPA" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub == 1) {
                Student s;
                cout << "Roll No: ";
                cin >> s.rollNo;
                cin.ignore();
                while (s.rollNo <= 0) {
                    cout << "Invalid. Enter positive Roll No: ";
                    cin >> s.rollNo;
                    cin.ignore();
                }
                cout << "Name: ";
                getline(cin, s.name);
                while (s.name.empty()) {
                    cout << "Name cannot be empty: ";
                    getline(cin, s.name);
                }
                cout << "Department: ";
                getline(cin, s.department);
                while (s.department.empty()) {
                    cout << "Department cannot be empty: ";
                    getline(cin, s.department);
                }
                cout << "CGPA (0.0 - 4.0): ";
                cin >> s.cgpa;
                cin.ignore();
                while (s.cgpa < 0.0 || s.cgpa > 4.0) {
                    cout << "Invalid CGPA. Enter between 0.0 and 4.0: ";
                    cin >> s.cgpa;
                    cin.ignore();
                }
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
                cout << "Enter Roll No to delete: ";
                cin >> roll;
                cin.ignore();
                studentManager.deleteStudent(roll);

            } else if (sub == 4) {
                studentManager.displayAll();

            } else if (sub == 5) {
                studentManager.displaySortedByCGPA();

            } else {
                cout << "Invalid option." << endl;
            }

        // =====================
        // MODULE 2 — COURSE
        // =====================
        } else if (choice == 2) {
            int sub;
            cout << "\n--- Course Registration ---" << endl;
            cout << "1. Register Course" << endl;
            cout << "2. Drop Course" << endl;
            cout << "3. Display Courses" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub == 1) {
                string course;
                cout << "Course name: ";
                getline(cin, course);
                while (course.empty()) {
                    cout << "Course name cannot be empty: ";
                    getline(cin, course);
                }
                courseManager.registerCourse(course);

            } else if (sub == 2) {
                string course;
                cout << "Course name to drop: ";
                getline(cin, course);
                while (course.empty()) {
                    cout << "Course name cannot be empty: ";
                    getline(cin, course);
                }
                courseManager.dropCourse(course);

            } else if (sub == 3) {
                courseManager.displayCourses();

            } else {
                cout << "Invalid option." << endl;
            }

        // =====================
        // MODULE 3 — LIBRARY
        // =====================
        } else if (choice == 3) {
            int sub;
            cout << "\n--- Library Management ---" << endl;
            cout << "1. Add Book" << endl;
            cout << "2. Search Book" << endl;
            cout << "3. Reserve Book" << endl;
            cout << "4. Process Reservation" << endl;
            cout << "5. Display Books" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub == 1) {
                Book b;
                cout << "Book ID: ";
                cin >> b.bookId;
                cin.ignore();
                while (b.bookId <= 0) {
                    cout << "Invalid. Enter positive Book ID: ";
                    cin >> b.bookId;
                    cin.ignore();
                }
                cout << "Title: ";
                getline(cin, b.title);
                while (b.title.empty()) {
                    cout << "Title cannot be empty: ";
                    getline(cin, b.title);
                }
                cout << "Author: ";
                getline(cin, b.author);
                while (b.author.empty()) {
                    cout << "Author cannot be empty: ";
                    getline(cin, b.author);
                }
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
                while (s.rollNo <= 0) {
                    cout << "Invalid. Enter positive Roll No: ";
                    cin >> s.rollNo;
                    cin.ignore();
                }
                cout << "Name: ";
                getline(cin, s.name);
                while (s.name.empty()) {
                    cout << "Name cannot be empty: ";
                    getline(cin, s.name);
                }
                s.department = "";
                s.cgpa = 0;
                libraryManager.reserveBook(s);

            } else if (sub == 4) {
                libraryManager.processReservation();

            } else if (sub == 5) {
                libraryManager.displayBooks();

            } else {
                cout << "Invalid option." << endl;
            }

        // =====================
        // MODULE 4 — COMPLAINT
        // =====================
        } else if (choice == 4) {
            int sub;
            cout << "\n--- Complaint Management ---" << endl;
            cout << "1. Add Normal Complaint" << endl;
            cout << "2. Process Normal Complaint" << endl;
            cout << "3. Add Token" << endl;
            cout << "4. Process Token" << endl;
            cout << "5. Add Emergency" << endl;
            cout << "6. Process Emergency" << endl;
            cout << "7. Undo Last Complaint" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub == 1) {
                Student s;
                cout << "Roll No: ";
                cin >> s.rollNo;
                cin.ignore();
                while (s.rollNo <= 0) {
                    cout << "Invalid. Enter positive Roll No: ";
                    cin >> s.rollNo;
                    cin.ignore();
                }
                cout << "Name: ";
                getline(cin, s.name);
                while (s.name.empty()) {
                    cout << "Name cannot be empty: ";
                    getline(cin, s.name);
                }
                s.department = "NORMAL";
                s.cgpa = 0;
                complaintManager.addNormalComplaint(s);

            } else if (sub == 2) {
                complaintManager.processNormalComplaint();

            } else if (sub == 3) {
                Student s;
                cout << "Roll No: ";
                cin >> s.rollNo;
                cin.ignore();
                while (s.rollNo <= 0) {
                    cout << "Invalid. Enter positive Roll No: ";
                    cin >> s.rollNo;
                    cin.ignore();
                }
                cout << "Name: ";
                getline(cin, s.name);
                while (s.name.empty()) {
                    cout << "Name cannot be empty: ";
                    getline(cin, s.name);
                }
                s.department = "TOKEN";
                s.cgpa = 0;
                complaintManager.addToken(s);

            } else if (sub == 4) {
                complaintManager.processToken();

            } else if (sub == 5) {
                Student s;
                cout << "Roll No: ";
                cin >> s.rollNo;
                cin.ignore();
                while (s.rollNo <= 0) {
                    cout << "Invalid. Enter positive Roll No: ";
                    cin >> s.rollNo;
                    cin.ignore();
                }
                cout << "Name: ";
                getline(cin, s.name);
                while (s.name.empty()) {
                    cout << "Name cannot be empty: ";
                    getline(cin, s.name);
                }
                cout << "Priority level (1=highest, 5=lowest): ";
                cin >> s.cgpa;
                cin.ignore();
                while (s.cgpa < 1 || s.cgpa > 5) {
                    cout << "Enter between 1 and 5: ";
                    cin >> s.cgpa;
                    cin.ignore();
                }
                s.department = "EMERGENCY";
                complaintManager.addEmergency(s);

            } else if (sub == 6) {
                complaintManager.processEmergency();

            } else if (sub == 7) {
                complaintManager.undoLast();

            } else {
                cout << "Invalid option." << endl;
            }

        // =====================
        // MODULE 5 — NAVIGATION
        // =====================
        } else if (choice == 5) {
            int sub;
            cout << "\n--- Campus Navigation ---" << endl;
            cout << "1. Display Map" << endl;
            cout << "2. BFS + DFS Traversal" << endl;
            cout << "3. Shortest Path (Dijkstra)" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub == 1) campusGraph.displayMap();
            else if (sub == 2) campusGraph.exploreAll(0);
            else if (sub == 3) campusGraph.findShortestPath(0);
            else cout << "Invalid option." << endl;

        // =====================
        // MODULE 6 — UNDO/REDO
        // =====================
        } else if (choice == 6) {
            int sub;
            cout << "\n--- Undo / Redo ---" << endl;
            cout << "1. Undo last action" << endl;
            cout << "2. Redo last undone action" << endl;
            cout << "3. Show stack sizes" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub == 1) undoRedoManager.undo();
            else if (sub == 2) undoRedoManager.redo();
            else if (sub == 3) undoRedoManager.displayStacks();
            else cout << "Invalid option." << endl;

        // =====================
        // MODULE 7 — HISTORY
        // =====================
        } else if (choice == 7) {
            int sub;
            cout << "\n--- Recently Viewed Records ---" << endl;
            cout << "1. Go Back" << endl;
            cout << "2. Go Forward" << endl;
            cout << "3. Display Full History" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub == 1) historyManager.goBack();
            else if (sub == 2) historyManager.goForward();
            else if (sub == 3) historyManager.displayHistory();
            else cout << "Invalid option." << endl;

        // =====================
        // MODULE 8 — SEARCH & SORT
        // =====================
        } else if (choice == 8) {
            int sub;
            cout << "\n--- Search & Sort Engine ---" << endl;
            cout << "1.  Linear Search" << endl;
            cout << "2.  Binary Search" << endl;
            cout << "3.  Hash Search" << endl;
            cout << "4.  BST Search" << endl;
            cout << "5.  Sort by CGPA (Bubble Sort)" << endl;
            cout << "6.  Sort by CGPA (Insertion Sort)" << endl;
            cout << "7.  Sort by CGPA (Merge Sort)" << endl;
            cout << "8.  Sort by CGPA (Quick Sort)" << endl;
            cout << "9.  Sort by CGPA (Heap Sort)" << endl;
            cout << "10. Run Sort Benchmark" << endl;
            cout << "Enter: ";
            cin >> sub;
            cin.ignore();

            if (sub >= 1 && sub <= 4) {
                int size = studentManager.getSize();
                if (size == 0) {
                    cout << "No students added yet. Add students first." << endl;
                } else {
                    Student* arr = studentManager.getArray();
                    int roll;
                    cout << "Enter Roll No to search: ";
                    cin >> roll;
                    cin.ignore();

                    if (sub == 1) {
                        int idx = searcher.linearSearch(arr, size, roll);
                        if (idx != -1)
                            cout << "[Linear Search O(n)] Found: "
                                 << arr[idx].name << " | CGPA: "
                                 << arr[idx].cgpa << endl;
                        else
                            cout << "[Linear Search] Not found." << endl;

                    } else if (sub == 2) {
                        Student* sorted = new Student[size];
                        for (int i = 0; i < size; i++) sorted[i] = arr[i];
                        sorter.bubbleSort(sorted, size);
                        int idx = searcher.binarySearch(sorted, size, roll);
                        if (idx != -1)
                            cout << "[Binary Search O(log n)] Found: "
                                 << sorted[idx].name << " | CGPA: "
                                 << sorted[idx].cgpa << endl;
                        else
                            cout << "[Binary Search] Not found." << endl;
                        delete[] sorted;

                    } else if (sub == 3) {
                        cout << "[Hash Search O(1)] ";
                        studentManager.searchByRollNo(roll);

                    } else if (sub == 4) {
                        cout << "[BST Search O(log n)] ";
                        studentManager.searchByRollNo(roll);
                    }
                    delete[] arr;
                }

            } else if (sub >= 5 && sub <= 9) {
                int size = studentManager.getSize();
                if (size == 0) {
                    cout << "No students added yet. Add students first." << endl;
                } else {
                    Student* arr = studentManager.getArray();
                    Student* copy = new Student[size];
                    for (int i = 0; i < size; i++) copy[i] = arr[i];

                    if (sub == 5) {
                        sorter.bubbleSort(copy, size);
                        cout << "[Bubble Sort O(n2)] Sorted by CGPA:" << endl;
                    } else if (sub == 6) {
                        sorter.insertionSort(copy, size);
                        cout << "[Insertion Sort O(n2)] Sorted by CGPA:" << endl;
                    } else if (sub == 7) {
                        sorter.mergeSort(copy, 0, size - 1);
                        cout << "[Merge Sort O(n log n)] Sorted by CGPA:" << endl;
                    } else if (sub == 8) {
                        sorter.quickSort(copy, 0, size - 1);
                        cout << "[Quick Sort O(n log n)] Sorted by CGPA:" << endl;
                    } else if (sub == 9) {
                        sorter.heapSort(copy, size);
                        cout << "[Heap Sort O(n log n)] Sorted by CGPA:" << endl;
                    }

                    for (int i = 0; i < size; i++) {
                        cout << copy[i].rollNo << " | "
                             << copy[i].name << " | "
                             << copy[i].department << " | "
                             << copy[i].cgpa << endl;
                    }
                    delete[] copy;
                    delete[] arr;
                }

            } else if (sub == 10) {
                cout << "\n[Sort Benchmark]" << endl;
                cout << "Run this command separately in terminal:" << endl;
                cout << "g++ tests/SortBenchmark.cpp src/SortingAlgorithms.cpp -I include -o bench" << endl;
                cout << "./bench" << endl;

            } else {
                cout << "Invalid option." << endl;
            }

        } else if (choice != 0) {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    cout << "Goodbye!" << endl;
    return 0;
}