#include<iostream>
using namespace std;
int main (){
    int tree[100];
    int n;
    cout<<"Enter the number of Elements in the array:";
    cin>>n;
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    for(int i=0;i<n;i++){
        cout<<"\nNode:"<<tree[i];
        int left=2*i+1;
        int right=2*i+2;
        if(left<n){
            cout<<"| Left:"<<tree[left];
        }
          if(right<n){
            cout<<"| Right:"<<tree[right];
        }
    }
}