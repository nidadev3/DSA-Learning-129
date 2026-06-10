#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include "../include/HashTable.h"
#include "../include/Queue.h"
#include "../include/Student.h"
#include <string>
using namespace std;

struct Book {
    int bookId;
    string title;
    string author;
    bool isAvailable;
};

class LibraryManager {
private:
    Book books[500];
    int bookCount;
    Queue reservationQueue;
public:
    LibraryManager();
    void addBook(Book b);
    void searchBook(int bookId);
    void reserveBook(Student s);
    void processReservation();
    void displayBooks();
};

#endif