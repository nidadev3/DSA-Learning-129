//when array is not full and have memory 
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[5]={1,2,3};
// int size=3;
// int capacity=5;
// if(size<capacity){
//     arr[size]=40;
//     size++;
// }
// else{
//     cout<<"Array is full"<<endl;
// }
// for(int i=0; i<size;i++){
//     cout<<arr[i]<<" ";
// }
// }

//when array is full 
#include<iostream>
using namespace std;

int main()
{
    int capacity = 5;
    int size = 5;

    int* arr = new int[capacity]{1,2,3,4,5};

    if(size == capacity)
    {
        int newcapacity = capacity * 2;

        int* newarr = new int[newcapacity];

        for(int i=0; i<size; i++)
        {
            newarr[i] = arr[i];
        }

        newarr[size] = 40;
        size++;

        delete[] arr;   // old memory free

        arr = newarr;
        capacity = newcapacity;
    }

    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
}