#include<iostream>
using namespace std;
int decending(int n){
if(n==0){
    return 0;
}
cout<< n <<" ";
return decending(n-1);
}
int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    decending(n);
    return 0;
}