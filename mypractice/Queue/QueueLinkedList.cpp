#include<iostream>
#include<queue>
using namespace std;


// struct Node {
//     int data;
//     Node* link;

//     Node(int value) {
//         data = value;
//         link = nullptr;
//     }
// };

// class Queue {
// private:
//     Node* head;
//     Node* tail;

// public:
//     Queue() {
//         head = tail = nullptr;
//     }

//     void push(int value) {
//         Node* newnode = new Node(value);
//         if (empty()) {
//             head = tail = newnode;
//         } else {
//             tail->link = newnode;
//             tail = newnode;
//         }
//     }

//     int pop() {
//         if (empty()) {
//             cout << "The Queue is Empty\n";
//             return -1;
//         }
//         Node* temp = head;
//         int value = temp->data;
//         head = head->link;
//         if (head == nullptr) {
//             tail = nullptr;
//         }
//         delete temp;
//         return value;
//     }

//     int front() {
//         if (empty()) {
//             cout << "The Queue is Empty\n";
//             return -1;
//         }
//         return head->data;
//     }

//     bool empty() {
//         return (head == nullptr);
//     }

//     void display() {
//         if (empty()) {
//             cout << "The Queue is Empty\n";
//             return;
//         }
//         Node* temp = head;
//         while (temp != nullptr) {
//             cout << temp->data << " -> ";
//             temp = temp->link;
//         }
//         cout << "NULL\n";
//     }
// };

// int main() {
//     Queue q;

//     q.push(10);
//     q.push(20);
//     q.push(30);

//     q.display();

//     cout << q.pop() << endl;
//     q.display();

//     cout << q.front() << endl;

//     return 0;
// }

//using stl
int main (){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
      cout << q.front() << endl;

    q.pop();

    cout << q.front() << endl;

    return 0;
}