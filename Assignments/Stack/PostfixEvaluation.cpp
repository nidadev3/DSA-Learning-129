#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    char exp[100];

    cout << "Enter postfix expression: ";
    cin >> exp;   // input as char array

    stack<int> s;

    for (int i = 0; exp[i] != '\0'; i++) {

        // If operand (digit)
        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');   // convert char to int
        }

        // If operator
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            switch (exp[i]) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    cout << "Result = " << s.top() << endl;

    return 0;
}
