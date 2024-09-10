#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="keshav sharma";
    string ans;
    stack<int> st;
    for(int i=0;i<str.size();i++){
        st.push(str[i]);
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<ans<<endl;
    return 0;
}