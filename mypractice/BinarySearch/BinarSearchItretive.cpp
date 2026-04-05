#include<iostream>
using namespace std;
int main (){
    //array
    int n;
    cout<<"Enter the capacity of the array:";
    cin>>n;
   int arr[n];
     cout<<"Enter the elements of the array:\n"
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //bubble sort
      for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}