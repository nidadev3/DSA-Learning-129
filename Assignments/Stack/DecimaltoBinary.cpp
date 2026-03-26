#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter decimal number: ";
    cin >> n;

    stack<int> s;

    while (n > 0) {
        int remainder = n % 2;
        s.push(remainder);
        n = n / 2;
    }

  
    while (!s.empty()) {
        cout << s.top();   
        s.pop();           
    }

    return 0;
}