#include "LibraryManager.h"
#include <iostream>
using namespace std;

LibraryManager::LibraryManager() {
    bookCount = 0;
}

void LibraryManager::addBook(Book b) {
    books[bookCount++] = b;
}

void LibraryManager::searchBook(int bookId) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookId == bookId) {
            cout << "Found: " << books[i].title
                 << " by " << books[i].author << endl;
            return;
        }
    }
    cout << "Book not found" << endl;
}

void LibraryManager::reserveBook(Student s) {
    reservationQueue.enqueue(s);
    cout << s.name << " added to reservation queue" << endl;
}

void LibraryManager::processReservation() {
    if (!reservationQueue.isEmpty()) {
        Student s = reservationQueue.dequeue();
        cout << "Book issued to: " << s.name << endl;
    } else {
        cout << "No reservations" << endl;
    }
}

void LibraryManager::displayBooks() {
    cout << "--- Books ---" << endl;
    for (int i = 0; i < bookCount; i++) {
        cout << books[i].bookId << " | "
             << books[i].title << " | "
             << books[i].author << endl;
    }
}