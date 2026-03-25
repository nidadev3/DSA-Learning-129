#include<iostream>
using namespace std;

#define max 100

char stackarr[max];
int top = -1;

// Check if stack is empty
bool isEmpty(){
    return (top == -1);
}

// Push function
void push(char x){
    if(top == max - 1){
        cout << "Stack is overflow";
        return;
    }
    top++;
    stackarr[top] = x;
}

// Pop function
char pop(){
    if(isEmpty()){
        cout << "Stack underflow";
        return '\0';
    }
    char val = stackarr[top];
    top--;
    return val;
}

// Peek function
char peek(){
    if(top == -1) return '\0';
    return stackarr[top];
}

// Precedence function
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

int main(){
    char exp[100];

    cout << "Enter the expression: ";
    cin.getline(exp, 100);

    for(int i = 0; exp[i] != '\0'; i++){

        // Operand (A-Z, a-z)
        if((exp[i] >= 'A' && exp[i] <= 'Z') || 
           (exp[i] >= 'a' && exp[i] <= 'z')){
            cout << exp[i];
        }

        // Opening bracket
        else if(exp[i] == '('){
            push(exp[i]);
        }

        // Closing bracket
        else if(exp[i] == ')'){
            while(!isEmpty() && peek() != '('){
                cout << pop();
            }
            pop(); // remove '('
        }

        // Operator
        else{
            while(!isEmpty() && precedence(peek()) >= precedence(exp[i])){
                cout << pop();
            }
            push(exp[i]);
        }
    }

    // Pop remaining operators
    while(!isEmpty()){
        cout << pop();
    }

    return 0;
}