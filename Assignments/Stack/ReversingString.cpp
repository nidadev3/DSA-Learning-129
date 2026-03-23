#include <iostream>
using namespace std;

int main() {
    string st;
    cout << "Enter string: ";
    cin >> st;

    int n = st.length();

    char arr[100];
    int top = -1;

   
    for (int i = 0; i < n; i++) {
        top++;
        arr[top] = st[i];
    }

  
    for (int i = 0; i < n; i++) {
        st[i] = arr[top];
        top--;
    }

    cout << "Reversed string: " << st;

    return 0;
}