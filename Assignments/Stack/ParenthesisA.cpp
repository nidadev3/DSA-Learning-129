// #include<iostream>
// #include<stack>
// using namespace std;

// bool isBalanced(char *s) {
//     stack<char> st;

//     for(int i = 0; s[i] != '\0'; i++) {
//         if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
//             st.push(s[i]);
//         }
//         else if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
//             if (st.empty()) return false;

//             char top = st.top();
//             st.pop();

//             if ((s[i] == ')' && top != '(') ||
//                 (s[i] == '}' && top != '{') ||
//                 (s[i] == ']' && top != '[')) {
//                 return false;
//             }
//         }
//     }
//     return st.empty();
// }

// int main() {
//     char exp[100];
//     cout << "Enter Expression: ";
//     cin.getline(exp, 100);

//     if (isBalanced(exp))
//         cout << "Balanced";
//     else
//         cout << "Not Balanced";
// }


//Without STL
#include<iostream>
using namespace std;

char stackarr[100];
int top = -1;

bool isEmpty() {
    return (top == -1);
}

void push(char x) {
    if (top == 99) {
        cout << "Overflow";
        return;
    }
    top++;
    stackarr[top] = x;
}

void pop() {
    if (isEmpty()) {
        cout << "Underflow";
        return;
    }
    top--;
}

char peek() {
    return stackarr[top];
}

bool isBalanced(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (isEmpty()) return false;

            char topchar = peek();
            pop();

            if ((s[i] == ')' && topchar != '(') ||
                (s[i] == '}' && topchar != '{') ||
                (s[i] == ']' && topchar != '[')) {
                return false;
            }
        }
    }
    return isEmpty();
}

int main() {
    char exp[100];
    cout << "Enter Expression: ";
    cin.getline(exp, 100);

    if (isBalanced(exp))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}