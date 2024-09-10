#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>& myStack,int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int num=myStack.top();
    myStack.pop();
    solve(myStack,x);
    myStack.push(num);
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    solve(st,100);
    return 0;
}