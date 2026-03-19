#include<iostream>
using namespace std;
class stack{
    private: 
    int arr[100];
    int top;
    int capacity;

    public:
    stack(int capacity)
    {
        this.capacity=capacity;
        top=-1;
    }
}