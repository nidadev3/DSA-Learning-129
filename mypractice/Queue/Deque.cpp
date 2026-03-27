// #include<iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;

//     Node(int value) {
//         data = value;
//         next = prev = nullptr;
//     }
// };

// class Deque {
// private:
//     Node* front;
//     Node* rear;

// public:
//     Deque() {
//         front = rear = nullptr;
//     }

//     bool empty() {
//         return (front == nullptr);
//     }

//     void push_front(int value) {
//         Node* newnode = new Node(value);

//         if (empty()) {
//             front = rear = newnode;
//         } else {
//             newnode->next = front;
//             front->prev = newnode;
//             front = newnode;
//         }
//     }

//     void push_back(int value) {
//         Node* newnode = new Node(value);

//         if (empty()) {
//             front = rear = newnode;
//         } else {
//             rear->next = newnode;
//             newnode->prev = rear;
//             rear = newnode;
//         }
//     }

//     void pop_front() {
//         if (empty()) {
//             cout << "Empty\n";
//             return;
//         }

//         Node* temp = front;
//         front = front->next;

//         if (front != nullptr)
//             front->prev = nullptr;
//         else
//             rear = nullptr;

//         delete temp;
//     }

//     void pop_back() {
//         if (empty()) {
//             cout << "Empty\n";
//             return;
//         }

//         Node* temp = rear;
//         rear = rear->prev;

//         if (rear != nullptr)
//             rear->next = nullptr;
//         else
//             front = nullptr;

//         delete temp;
//     }

//     int getFront() {
//         if (empty()) return -1;
//         return front->data;
//     }

//     int getRear() {
//         if (empty()) return -1;
//         return rear->data;
//     }

//     void display() {
//         Node* temp = front;
//         while (temp != nullptr) {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     Deque d;

//     d.push_back(10);
//     d.push_back(20);
//     d.push_front(5);

//     d.display();

//     d.pop_front();
//     d.display();

//     d.pop_back();
//     d.display();

//     return 0;
// }


//using stl

#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(15);

    dq.pop_back();
    dq.pop_front();

    dq.push_front(4);
    dq.push_front(10);
    dq.push_front(5);

    dq.pop_back();
    dq.pop_front();

    return 0;
}