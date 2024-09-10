#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& myStack,int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int num=myStack.top();
    myStack.pop();
    insertAtBottom(myStack,x);
    myStack.push(num);
}

void reverseStack(stack<int> &St) {
    if(St.empty()){
        return;
    }
    int num=St.top();
    St.pop();
    reverseStack(St);
    insertAtBottom(St,num);
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    reverseStack(st);
    return 0;
}