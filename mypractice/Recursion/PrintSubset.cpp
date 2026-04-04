#include<iostream>
using namespace std;
void subset(int arr[], int n, int subset[], int i, int subsetsize){
    if(i==n){
        cout<<"{";
        for(int j=0;j<subsetsize;j++){
            cout<<subset[j]<<" ";
        }
        cout<<"{" <<endl; 
        return;
    }
    
}