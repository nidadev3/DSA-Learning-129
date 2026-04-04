#include<iostream>
using namespace std;
void psubset(int arr[], int n, int subset[], int i, int subsetsize){
    if(i==n){
        cout<<"{";
        for(int j=0;j<subsetsize;j++){
            cout<<subset[j]<<" ";
        }
        cout<<"{" <<endl; 
        return;
    }
    subset[subsetsize]==arr[i];
    psubset(arr,subset,i+1,subsetsize+1);
    psubset(arr,n,subset,i+1,subsetsize);
}
