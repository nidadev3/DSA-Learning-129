#include <iostream>
using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the size of the array: ";
//     cin>>n;
//     int* arr=new int[n];
//     cout<<"Enter "<<n<<" elements: ";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<"Array elements: ";
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// int main(){
//     int arr[5]={4,3,-18,-19,0};
//     int smallest=0;
//     for(int i=0;i<5;i++){
//         if(arr[i]<smallest){
//             smallest=arr[i];
//         }   
//     }
//     cout<<"Smallest element in the array: "<<smallest<<endl;
// }

// int main(){
//     int arr[5]={4,3,-18,-19,0};
//     int Largest=0;
//     for(int i=0;i<5;i++){
//         if(arr[i]>Largest){
//             Largest=arr[i];
//         }   
//     }
//     cout<<"Largest element in the array: "<<Largest<<endl;
// }
//Printing tha data in the array
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array elements: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}