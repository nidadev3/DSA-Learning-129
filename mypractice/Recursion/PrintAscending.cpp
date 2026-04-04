#include<iostream>
using namespace std;
int ascending(int n){
    if(n==0){
        return 0;
    }
    ascending(n-1);
    cout<<n<<" ";
}
int main (){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    ascending(n);
    return 0;
}