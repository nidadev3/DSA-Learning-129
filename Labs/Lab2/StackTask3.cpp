#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluate(string exp) {
    stack<int> st;

    for(int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if(isdigit(ch)) {
            st.push(ch - '0');
        }
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            if(ch == '+') st.push(val1 + val2);
            else if(ch == '-') st.push(val1 - val2);
            else if(ch == '*') st.push(val1 * val2);
            else if(ch == '/') st.push(val1 / val2);
            else if(ch == '^') st.push(pow(val1, val2));
        }
    }

    return st.top();
}

int main() {

    string exp;
    cin >> exp;

    cout << evaluate(exp);

    return 0;
}