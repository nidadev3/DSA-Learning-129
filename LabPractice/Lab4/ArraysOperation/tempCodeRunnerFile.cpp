#include<iostream>
using namespace std; 
int main (){
    int arr[100];
    int n;
    cout<<"Enter the size of array :";
    cin>>n;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
      
    }
      cout<<"The largest element in array is:"<<largest;
}