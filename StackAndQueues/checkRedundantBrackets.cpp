#include<bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isRedundant=true;
                while(st.top()!='('){
                    char peek=st.top();
                    if(peek=='+' || peek=='-' || peek=='*' || peek=='/'){
                        isRedundant=false;
                    }
                    st.pop();
                }
                if(isRedundant==true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;    
}

int main(){
    string str="((a+b))";
    cout<<findRedundantBrackets(str)<<endl;
    return 0;
}