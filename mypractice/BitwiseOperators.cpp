#include<iostream>
using namespace std;
int main (){
    int a=5;
    int b=8;
    cout<<"a&b: "<<(a&b)<<endl; // bitwise AND
    cout<<"a|b: "<<(a|b)<<endl; // bitwise OR
    cout<<"a^b: "<<(a^b)<<endl; // bitwise XOR
    cout<<"a<<1: "<<(a<<1)<<endl; // left shift
    cout<<"a>>1: "<<(a>>1)<<endl; // right shift
    cout<<"~a: "<<(~a)<<endl; // bitwise NOT
}