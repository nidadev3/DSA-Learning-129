#include<iostream>
using namespace std;
//sum from 1 to n
void sum(int n,int acc){
    if(n==0){
       cout<< acc;
       return;
    }
    sum(n-1,acc+n);
}
int main (){
    sum(5,0);

}