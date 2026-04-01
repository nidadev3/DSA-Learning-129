#include <iostream>
using namespace std;
struct job {
    int id;
    string ownerName;
    string documentName;
};
class queue {
private:
    job *arr;
    int capacity;
    int size;
    int front;
    int rear;
public:
    queue(int cap) {
        capacity = cap;
        arr = new job[capacity];
        size = 0;
        front = 0;
        rear = -1;
    }
    ~queue() { 
        delete[] arr;
     }
    bool rempty() { 
        return size == 0; 
    }
    bool rfull() { 
        return size == capacity;
     }
    void enqueue(job b) {
        if (rfull()) { cout << "Printer is Full\n"; 
            return;
         }
        rear = (rear + 1) % capacity;
        arr[rear] = b;
        size++;
    }
    job dequeue() {
        if (rempty()) { cout << "No jobs in queue\n";
             return job(); 
            }
        job b = arr[front];
        front = (front + 1) % capacity;
        size--;
        return b;
    }
    void display() {
        if (rempty()) { cout << "Queue is Empty\n";
             return; 
            }
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            cout << "ID: " << arr[index].id
                 << ", Owner: " << arr[index].ownerName
                 << ", Document: " << arr[index].documentName << endl;
        }
    }
    void checkStatus(int id) {
        if (rempty()) { cout << "Queue is Empty\n"; 
            return; 
        }
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            if (arr[index].id == id) {
                cout << "Job Found - Owner: " << arr[index].ownerName
                     << ", Document: " << arr[index].documentName << endl;
                return;
            }
        }
        cout << "Job not found\n";
    }
};
int main() {
    int cap;
    cout << "Enter queue capacity: ";
    cin >> cap;
    queue q(cap);
    int choice;
    do {
        cout << "\n1. Add Print Job\n2. Print Next\n3. Display Queue\n4. Check Job Status\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            job j;
            cout << "Enter ID: "; 
            cin >> j.id;
            cout << "Enter Owner Name: "; 
            cin >> j.ownerName;
            cout << "Enter Document Name: ";
             cin >> j.documentName;
            q.enqueue(j);
        } else if (choice == 2) {
            job j = q.dequeue();
            if (j.id != 0) {
                cout << "Printing - ID: " << j.id
                     << ", Owner: " << j.ownerName
                     << ", Document: " << j.documentName << endl;
            }
        } else if (choice == 3) {
            q.display();
        } else if (choice == 4) {
            int id; cout << "Enter ID: "; cin >> id;
            q.checkStatus(id);
        } else if (choice == 5) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}