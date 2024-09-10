#include<bits/stdc++.h>
using namespace std;

void display(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void solve(stack<int>&inputStack,int cnt,int N){
   if(cnt==N/2){
      inputStack.pop();
      return ;
   }
   int num=inputStack.top();
   inputStack.pop();
   solve(inputStack, cnt+1, N);
   inputStack.push(num);
}

void deleteMiddleElement(stack<int> &st){
    int s=st.size();
    int mid=(s+1)/2;
    int cnt=0;
    vector<int> ans;
    while(cnt<=mid){
        ans.push_back(st.top());
        st.pop();
        cnt++;
    }
    // display(st);
    // cout<<"Array Elements : ";
    // for(int i=0;i<ans.size();i++)   cout<<ans[i]<<"  ";
    for(int i=ans.size()-2;i>=0;i--){
        st.push(ans[i]);
    }
    display(st);
}

int main(){
    stack<int> st;
    // st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    display(st);
    deleteMiddleElement(st);
    return 0;
}