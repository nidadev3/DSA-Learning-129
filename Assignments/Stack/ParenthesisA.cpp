#include<iostream>
#include<string>
#include<stack>
using namespace std;
#define max=100;
char st[max];

bool isBalanced(char *s){
    for(int i=0;i<s.length;i++){
        if(
            s[i]='['|| s[i]='{'|| s[i]='('
        ){
            st.push(s);
        }
        else if( s[i]=']'|| s[i]='}'|| s[i]=')')
        {
if(st.empty()) return false;
s.top=st.top();
st.pop();
    
         if ((s == ')' && top != '(') ||
                (s == '}' && top != '{') ||
                (s == ']' && top != '[')) {
                return false;
    }
}
}
return st.empty();}


int main (){
    char exp[100];
    cout<<"Enter the Expression:";
    cin.getline(exp,100);
     if (isBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}