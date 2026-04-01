#include<iostream>
#include<queue>
using namespace std;
class MyStack{
    public:
    queue<int>q1;
    queue<int>q2;
    MyStack(){

    }
    void push(int x){
while(!q1.empty()){
    q2.push(q1.front());
    q1.pop();
}
q1.push(x);
while(!q2.empty()){
 q1.push(q2.front());
q2.pop();
}
    }


 int pop(){
int ans=q1.front();
q1.pop();
return ans;
 }



    int top(){
return q1.front();
    }
    bool empty(){
return q1.empty();
    }
};
int main() {
    MyStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;

    cout << "Pop: " << s.pop() << endl;

    cout << "Top after pop: " << s.top() << endl;

    cout << "Is empty? " << s.empty() << endl;

    s.pop();
    s.pop();

    cout << "Is empty after removing all? " << s.empty() << endl;

    return 0;
}