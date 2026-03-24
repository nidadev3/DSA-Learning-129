#include<iostream>
using namespace std;

#define max 100
char stackarr[max];
int top=-1;
bool isEmpty(){
    return(top==-1);
}
void push (char x){
    if(top==99){
        cout<<"Stack is overflow";
        return;
    }
    top++;
    stackarr[top]=x;
}
char pop(){
    if(isEmpty()){
        cout << "Stack underflow";
        return -1;
    }
    char val = stackarr[top];
    top--;
    return val;
}
char peek(){
return stackarr[top];
}
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}





int main (){
    char exp[100];
    cout<<"Enter the expression:";
    cin.getline(exp,100);

}