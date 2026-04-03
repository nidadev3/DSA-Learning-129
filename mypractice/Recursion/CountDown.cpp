#include<iostream>
using namespace std;

void countdown(int n){
    if(n == 0){
        cout << "Blast off!" << endl;
        return;
    }

    cout << n << endl;  

    countdown(n - 1);   
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    countdown(n);   

    return 0;
}