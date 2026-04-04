#include<iostream>
using namespace std;
void psubset(int arr[], int n, int subset[], int i, int subsetsize){
    if(i==n){
        cout<<"{";
        for(int j=0;j<subsetsize;j++){
            cout<<subset[j]<<" ";
        }
        cout<<"}" <<endl; 
        return;
    }
    subset[subsetsize]=arr[i];
    psubset(arr,n,subset,i+1,subsetsize+1);
    psubset(arr,n,subset,i+1,subsetsize);
}
int main(){
    int arr[]={1,2,3,4};
    int n=4;
    int subset[4];
    psubset(arr,n,subset,0,0);
    return 0;
}