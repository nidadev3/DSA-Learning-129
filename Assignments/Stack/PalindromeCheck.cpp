#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;

    
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

  
    bool isPalindrome = true;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != s.top()) {
            isPalindrome = false;
            break;
        }
        s.pop();
    }

    if (isPalindrome)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}